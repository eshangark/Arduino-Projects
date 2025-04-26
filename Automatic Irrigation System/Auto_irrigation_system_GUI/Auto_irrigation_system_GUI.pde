import processing.serial.*;
import java.util.ArrayList;

Serial           port;
int              maxPoints    = 200;   // keep up to 200 readings
ArrayList<Float> moistureData, tempData, humData;
int              margin       = 80;

// Aesthetic palette
color bgTop       = color(240,240,240);
color bgBot       = color(200,200,200);
color gridColor   = color(180,180,180,50);
color moistColor  = color(100,180,240,200);
color tempColor   = color(240,100,100,200);
color humColor    = color(100,240,100,200);
color tooltipBg   = color(255,255,255,230);

void setup() {
  size(1000,600);
  smooth(8);
  textFont(createFont("SansSerif",14));
  moistureData = new ArrayList<Float>();
  tempData     = new ArrayList<Float>();
  humData      = new ArrayList<Float>();
  println("Serial ports:", Serial.list());
  port = new Serial(this, Serial.list()[0], 9600);
  port.bufferUntil('\n');
  frameRate(30);
}

void draw() {
  drawGradientBackground();
  drawGrid();
  int panelH = (height - 2*margin)/3;
  drawPointsPanel(moistureData, margin,           panelH,  0, 100, moistColor, "Soil Moisture (%)");
  drawPointsPanel(tempData,     margin+panelH,    panelH, -10,  60, tempColor,  "Temperature (°C)");
  drawPointsPanel(humData,      margin+2*panelH,  panelH,   0, 100, humColor,   "Humidity (%)");
  drawCrosshair();
}

void drawGradientBackground() {
  for (int y=0; y<height; y++){
    stroke(lerpColor(bgTop, bgBot, map(y,0,height,0,1)));
    line(0,y,width,y);
  }
}

void drawGrid() {
  stroke(gridColor);
  strokeWeight(1);
  noFill();
  for (int x=margin; x<width-margin; x+=50)    line(x, margin, x, height-margin);
  for (int y=margin; y<height-margin; y+=50)   line(margin, y, width-margin, y);
}

void drawPointsPanel(ArrayList<Float> data, int y0, int h,
                     float vMin, float vMax, color dotColor, String label) {
  float left = margin, right = width-margin;
  float top  = y0,      bot   = y0 + h;
  stroke(200); noFill();
  rect(left,top,right-left,bot-top);
  
  int count = data.size();
  int start = max(0, count - maxPoints);
  float plotW = right - left;
  float spacing = plotW/(maxPoints-1);
  
  // draw connecting lines & points
  noStroke(); fill(dotColor);
  for (int i = start; i < count; i++) {
    float v = data.get(i);
    float x = left + (i - start)*spacing;
    float y = map(v, vMin, vMax, bot, top);
    
    if (i > start) {
      float pv = data.get(i-1);
      float px = left + (i-1 - start)*spacing;
      float py = map(pv, vMin, vMax, bot, top);
      stroke(dotColor);
      strokeWeight(2);
      line(px, py, x, y);
      noStroke();
      fill(dotColor);
    }
    
    ellipse(x, y, 8, 8);
  }
  
  fill(50);
  textSize(16);
  textAlign(LEFT, TOP);
  text(label, left+10, top+10);
  if (count > 0) {
    textAlign(RIGHT, TOP);
    text(nf(data.get(count-1),0,1), right-10, top+10);
  }
}

void drawCrosshair(){
  if (mouseX<margin || mouseX>width-margin || mouseY<margin || mouseY>height-margin) return;
  stroke(255,0,0,150);
  line(mouseX,margin, mouseX, height-margin);
  
  int count = moistureData.size();
  if (count==0) return;
  int show = min(count, maxPoints);
  int idx  = int(map(mouseX, margin, width-margin, 0, show-1));
  idx = constrain(idx,0,show-1);
  int base = count - show;
  
  float m = moistureData.get(base+idx),
        t = tempData.get(base+idx),
        h = humData.get(base+idx);
  String info = "M:"+nf(m,0,1)+"%  T:"+nf(t,0,1)+"°C  H:"+nf(h,0,1)+"%";
  float tw = textWidth(info)+10, th=20;
  float tx=mouseX+10, ty=mouseY-th-10;
  if (tx+tw>width) tx=mouseX-tw-10;
  if (ty<margin)   ty=mouseY+10;
  noStroke(); fill(tooltipBg);
  rect(tx,ty,tw,th,5);
  fill(50); textAlign(LEFT,CENTER);
  text(info, tx+5, ty+th/2);
}

void serialEvent(Serial p){
  String line = p.readStringUntil('\n');
  if (line==null) return;
  line=trim(line);
  String[] toks = split(line, ',');
  if (toks.length<3) return;
  try {
    appendData(moistureData, float(toks[0]));
    appendData(tempData,     float(toks[1]));
    appendData(humData,      float(toks[2]));
  } catch(Exception e){
    println("Parse error:", line);
  }
}

void appendData(ArrayList<Float> list, float v){
  list.add(v);
  if (list.size()>maxPoints) list.remove(0);
}
