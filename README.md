# Teensy-shortcuts

This programm is a shorcut manager for applications on your computer.

## Hardware

Use a Teensy 3.1 board, pushbuttons and a LCD to display the current Profile.

## Usage

The program is bassed on pushbuttons that send keyboard strokes on their rising edge.

## Software supported

1. Arduino IDE (Verify & upload).

## Add pushbuttons

1. Connect the pushbutton to a digital pin. Use a pulldown resistror to pushbuttons.
2. Create a Bounce objet to debounce the pushbutton:
<pre lang="arduino"><code>
  Bounce *name_of_your_button* = Bounce(*pin_of_your_button*,10);
</code></pre>
3. Use:
<pre lang="arduino"><code>
  pinMode(*pinNumer or variable*,INPUT);
</code></pre>
4. At loop update the button, then watch for the risindEdge of that button and send keystrokes. ie:

<pre lang="arduino"><code>

  btn1.update();
 
  
  if (btn1.risingEdge()){
    Serial.println("risingEdge btn1");
    Keyboard.set_modifier(MODIFIERKEY_CTRL);
    Keyboard.set_key1(KEY_R);
    Keyboard.send_now();

  }
</code></pre>


## Add program profile

-- To Do --

## Add shorcuts

Check out your favorite program shortcuts and know which key combination activate them, then go to [teensy keys](https://www.pjrc.com/teensy/td_keyboard.html) and look for your keys combination.

Place them inside of:
<pre lang="arduino"><code>    
    if (name_of_your_button.risingEdge()){
      //Send keystrokes
    }
</code></pre>
