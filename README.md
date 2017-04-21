# ArduinoPuzzleBox

<p>The goal of this puzzle is to manipulate and explore the box to turn on all the lights! The app uses various sensors and an Arduino to control 12 red LEDS. Every sensor must be utilized in some way to solve the puzzle.</p>

<h1>How it Works</h1>

<p>The project uses an Arduino Uno to control 12 red LED lights, and read from a tilt sensor, an ultrasonic distance sensor, a 2-axis joystick, and a push button, plus a lot of jumper wires (male-male, male-female, and female-female). All this is powered by a 9 volt battery with resistors to help protect the lifespan of the LED lights and the functionality of the button and tilt switch.</p>

<h3>The Setup</h3>
<img src="Fritzing Exports/startingSketch_bb.png" alt='how it works' width="800">

<h1>Tutorial</h1>
<h3>You Need:</h3>
<ul>
<li><b>Electronic</b></li>
<li>an arduino and necessary components (listed below)</li>
<li>jumper cables (I used aproximately 40 male-male and 40 male-female)</li>
<li>electrical wire (insulated)</li>
<li><b>Building the box</b></li>
<li>foam core (I used black)</li>
<li>hot glue</li>
<li>a precision knife</li>
<li>a metal ruler or square</li>
</ul>

<h3>Arduino Parts List</h3>
<table>
  <thead>
   <tr>
    <th></th>
    <th>Part Type</th>
    <th>Properties</th>
    </tr>
  </thead>
  <tbody>
  <tr>
    <td>1</td>
    <td>Arduino Uno (Rev3) - ICSP</td>
    <td class="props">type Arduino UNO (Rev3) - ICSP (w/o icsp2)</td>
</tr><tr>
    <td>1</td>
    <td>Ultrasonic Distance Sensor (hc-sr04)</td>
    <td class="props">variant hc-sr04</td>
</tr><tr>
    <td>12</td>
    <td>Red (633nm) LED</td>
    <td class="props">color Red (633nm); package 5 mm [THT]; leg yes</td>
</tr><tr>
    <td>1</td>
    <td>Thumb Joystick</td>
    <td class="props">2-Axis</td>
</tr><tr>
    <td>15</td>
    <td>220Ω Resistor</td>
    <td class="props">package THT; tolerance ±5%; resistance 220Ω; bands 4; pin spacing 400 mil</td>
</tr><tr>
    <td>1</td>
    <td>Tilt Switch</td>
    <td class="props">package THT; tilt mechanism Mechanical Ball</td>
</tr><tr>
    <td>1</td>
    <td>Pushbutton</td>
    <td class="props">package [THT]</td>
</tr><tr>
    <td>1</td>
    <td>Battery block 9V</td>
    <td class="props">voltage 9V</td>
</tr>
  </tbody>
</table>

