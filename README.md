# ArduinoPuzzleBox

<p>The goal of this puzzle is to manipulate and explore the box to turn on all the lights! The app uses various sensors and an Arduino to control 12 red LEDS. Every sensor must be utilized in some way to solve the puzzle.</p>

<h1>How it Works</h1>

<p>The project uses an Arduino Uno to control 12 red LED lights, and read from a tilt sensor, an ultrasonic distance sensor, a 2-axis joystick, and a push button, plus a lot of jumper wires (male-male, male-female, and female-female). All this is powered by a 9 volt battery with resistors to help protect the lifespan of the LED lights and the functionality of the button and tilt switch.</p>

<h3>The Setup</h3>
<img src="Fritzing Exports/startingSketch_bb.png" alt='how it works' width="800">

<h1>Tutorial</h1>
<h3>You Need:</h3>

<b>For the electronics</b>
<ul>
<li>an arduino and necessary components (listed below)</li>
<li>jumper cables (I used aproximately 40 male-male and 40 male-female)</li>
</ul>
<b>For the box</b>
<ul>
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

<h3>Step One - The Code</h3>
<img src='build/unfoldedBox' alt='unfolded box'>


<h3>Step Two - Building the Enclosure</h3>
<img src='build/unfoldedBox' alt='unfolded box'>
<ul>
<li>Decide how large you want your box. I chose 15x15 cm squares. 
Remember that you will have to wire all your components together 
when the box is mostly built so leave yourself room to work if you need it.</li>
<li>Measure six squares in your choice layed out like the picture above 
(Like a cross with four squares up-down and three squares across) </li>
<li>Use a precision knife to cut out the box. 
(I find that it takes at least two passes with the knife and that the knife dulls quickly so be careful)</li>
<li>On one side of the box score score the lines between each box. Be careful not to cut through the foam entirely. Aim for either one pass of the knife, or just through one layer of the paper and most of the foam in the core. This will allow you to fold the foam core</li>
<li>Cut out holes for any hardware that needs to be outside the box
  <ul>
    <li>Cut two round holes for the ultrasonic sensor. If you measure and cut carefully that could be enough to hold the sensor in place!</li>
    <li>Cut a small hole for the push button that will serve as the reset button where you wish to place the reset button (I chose the top)</li>
    <li>Cut a hole for the joystick on the top of the box</li>
    <li>Poke two small holes for each LED on the top of the box</li>
  </ul>
</li>
<li>Attach any components that will be difficult to install later. (Make sure to leave room to add wires later when the box is formed. I used a combination of extra foam core and hotglue to secure the push button and the joystick)</li>
<li>Use hotglue on the inside or outside seams of the cube to hotglue all but one panel into a cube
  <ul>
    <li>Fold one panel 90 degrees and secure with hotglue on the fold. (I did both the inside and outside seams for extra stability)</li>
    <li>Repeat until there is one pannel not secured into the box</li>
  </ul>
</li>
</ul>



<ul>
<li></li>
<li></li>
<li></li>
<li></li>
<li></li>
<li></li>
<li></li>
<li></li>
</ul>


