import processing.serial.*;

Serial myPort;
String inString = "";
// Variables to hold the latest servo angle and sensor distance from Arduino
int iAngle = 0;
int iDistance = 0;

// Radar display parameters:
// We place the radar so its origin is at the bottom center of the window.
float centerX, centerY;
float radarRadius;              // Maximum radius (in pixels) for the radar display
float maxSensorDistance = 40;   // Maximum distance (in centimeters) you want to display
float scaleFactor;              // How many pixels represent one centimeter

void setup() {
  size(1200, 700);
  background(0);
  
  // Set the radar origin at bottom-center (with a margin from the bottom)
  centerX = width / 2;
  centerY = height - 50;
  
  // Set the radar radius: adjust so that it roughly spans the upper part of the screen
  radarRadius = (width / 2) - 50;
  
  // Scale factor: how many pixels per centimeter (assume maxSensorDistance fills the radar)
  scaleFactor = radarRadius / maxSensorDistance;
  
  // Print available serial ports for debugging.
  println(Serial.list());
  // IMPORTANT: Change "COM7" or use Serial.list()[0] as needed for your Arduino's port.
  myPort = new Serial(this, Serial.list()[0], 9600);
  // Use newline as the delimiter (Arduino prints newline at the end)
  myPort.bufferUntil('\n');
}

void draw() {
  // Create a slight fading effect for a motion-blur look.
  noStroke();
  fill(0, 50);
  rect(0, 0, width, height);
  
  // Draw the radar grid background.
  drawGrid();
  
  // Map the incoming servo angle to a display angle.
  // We want the mapping such that:
  //   Servo 15   → Display 315° (far right)
  //   Servo 90   → Display 270° (center, i.e. straight up)
  //   Servo 165  → Display 225° (far left)
  float displayAngle = map(iAngle, 15, 165, 315, 225);
  
  // Draw the sweep line (green) along the current display angle.
  stroke(0, 255, 0);
  strokeWeight(3);
  float endX = centerX + radarRadius * cos(radians(displayAngle));
  float endY = centerY + radarRadius * sin(radians(displayAngle));
  line(centerX, centerY, endX, endY);
  
  // Draw a red "object" line instead of a dot:
  // If an object is detected (iDistance > 0 and within maxSensorDistance),
  // draw a thick red line from the measured point (object location) out to the edge of the radar.
  if (iDistance > 0 && iDistance < maxSensorDistance) {
    float dPixels = iDistance * scaleFactor;
    stroke(255, 0, 0);
    strokeWeight(9);
    // Calculate the object’s measured position.
    float objX = centerX + dPixels * cos(radians(displayAngle));
    float objY = centerY + dPixels * sin(radians(displayAngle));
    // Draw a line from the object out to the edge.
    line(objX, objY, endX, endY);
  }
  
  // Draw informational text.
  fill(0, 255, 0);
  textSize(20);
  text("Servo Angle: " + iAngle + "°", 20, 30);
  text("Distance: " + iDistance + " cm", 20, 60);
}

void drawGrid() {
  stroke(0, 255, 0);
  strokeWeight(2);
  noFill();
  
  // Draw the semicircular radar arc.
  // With the origin at (centerX, centerY) at the bottom,
  // drawing an arc from PI to TWO_PI produces a semicircle (front view).
  arc(centerX, centerY, radarRadius * 2, radarRadius * 2, PI, TWO_PI);
  
  // Draw concentric semicircular rings (range markers).
  int rings = 4;
  for (int i = 1; i <= rings; i++) {
    float r = radarRadius * (i / float(rings));
    arc(centerX, centerY, r * 2, r * 2, PI, TWO_PI);
  }
  
  // Draw radial lines at key servo angles.
  int[] servoAngles = {15, 45, 75, 90, 105, 135, 165};
  for (int a : servoAngles) {
    float dispAng = map(a, 15, 165, 315, 225);
    float x = centerX + radarRadius * cos(radians(dispAng));
    float y = centerY + radarRadius * sin(radians(dispAng));
    line(centerX, centerY, x, y);
  }
}

void serialEvent(Serial myPort) {
  inString = myPort.readStringUntil('\n');
  if (inString != null) {
    inString = trim(inString);
    // Expecting the Arduino to send "angle,distance"
    String[] parts = split(inString, ",");
    if (parts.length == 2) {
      iAngle = int(parts[0]);
      iDistance = int(parts[1]);
      // Debug print
      println("Servo Angle: " + iAngle + " | Distance: " + iDistance);
    }
  }
}
