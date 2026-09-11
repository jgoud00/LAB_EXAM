# Lab Write-up

### Problem Statement
Design a responsive SensorGrid monitoring interface using HTML5/CSS, publish it to GitHub with at least three meaningful commits, and create an ESP32 Wokwi simulation with an LED blinking on a 2-second ON and 1-second OFF cycle.

### Aim
To practically implement semantic HTML5 structures, responsive CSS layouts (Grid/Flexbox), Git version control workflows, and basic ESP32 GPIO hardware interfacing.

### Procedure / Algorithm
1. **Web UI Design:** 
   - Created a semantic HTML5 structure with sections for Dashboard, Sensors, Analytics, and Alerts.
   - Applied CSS Grid for the main layout and Flexbox to align internal components.
   - Designed distinct visual states (using CSS classes) to display sensors as ONLINE (green), OFFLINE (gray), and ALERT (red).
2. **Version Control:**
   - Initialized a local Git repository and staged the project files.
   - Created three distinct commits separating the simulation setup, HTML structure, and CSS styling.
   - Pushed the tracked repository to the provided remote GitHub URL.
3. **ESP32 Simulation:**
   - Configured an ESP32 circuit in Wokwi utilizing the built-in LED on GPIO 2.
   - Programmed the microcontroller setup to initialize the pin as an output.
   - Created an infinite loop algorithm that turns the pin HIGH for 2000ms, then LOW for 1000ms.

### Important Code / Commands

**Git Version Control Commands:**
```bash
git init
git add .
git commit -m "Add UI structure and CSS styles"
git remote add origin https://github.com/jgoud00/LAB_EXAM.git
git push -u origin main
```

**Core ESP32 Logic Snippet:**
```cpp
void loop() {
  digitalWrite(ledPin, HIGH);
  Serial.println("LED Status: ON");
  delay(2000);

  digitalWrite(ledPin, LOW);
  Serial.println("LED Status: OFF");
  delay(1000);

  blinkCount++;
  Serial.print("Completed blink cycles: ");
  Serial.println(blinkCount);
}
```

### Output / Result
- A fully responsive web interface successfully displaying dynamic sensor statuses.
- A functional ESP32 simulation running the precise 2-second ON, 1-second OFF LED cycle.
- The entire project successfully published to the remote GitHub repository with a clean commit history.

### Conclusion
The lab successfully demonstrated the integration of frontend web development with responsive design principles, practical application of version control via Git, and foundational IoT hardware programming using the ESP32 microcontroller.
