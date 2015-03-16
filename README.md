# Teensy-shortcuts

This programm is a shortcut manager for applications on your computer.
Up to 4 profiles (easy to implement more).
Up to 6 buttons with display info of each one. It's really simple to add more, but without showing info in the LCD Screen.

## Hardware

Use a Teensy 3.1 board, pushbuttons and a LCD to display the current Profile.

## Usage

The program is bassed on pushbuttons that send keyboard strokes on their rising edge.
Just click the button and let the magic happend!
## Software supported

1. Arduino IDE:
  1.  Verify
  2.  Upload
  3.  Monitor
  4.  Auto Format
2. Sublime Text 3 with Stino plugin :
  1.  Verify
  2.  Upload
  3.  Monitor
  4.  Auto Format

##How to: Add pushbuttons

1. Connect the pushbutton to a digital pin. Use a pulldown resistror to pushbuttons.
2. Create a Bounce objet to debounce the pushbutton:
<pre lang="arduino"><code>
  Bounce *name_of_your_button* = Bounce(*pin_of_your_button*,10);
</code></pre>
3. Use:
<pre lang="arduino"><code>
  pinMode(*pinNumer or variable*,INPUT);
</code></pre>
4. At <pre lang="Arduino">profileActions</pre> update the button, then watch for the risindEdge of that button and send keystrokes. ie:

<pre lang="arduino"><code>

  btn1.update();
   
  if (btn1.risingEdge()){
    Serial.println("risingEdge btn1");
    Keyboard.set_modifier(MODIFIERKEY_CTRL);
    Keyboard.set_key1(KEY_R);
    Keyboard.send_now();

  }
</code></pre>


##How to: Add program profile

Create a profile struct:
<pre lang="arduino"><code>    
  struct Profile profile1;
</code></pre>

Add profile name and shortcuts names:

<pre lang="arduino"><code>    
  strcpy (profile1.name,"Arduino IDE");
  strcpy (profile1.shortcut1,"Verify");
  strcpy (profile1.shortcut2,"Upload");
  strcpy (profile1.shortcut3,"Monitor");
  strcpy (profile1.shortcut4,"AutoFormat");
</code></pre>

Add shortcuts inside of <pre lang="arduino"><code>profileActions</code></pre> function

##How to: Add shortcuts

Check out your favorite program shortcuts and know which key combination activate them, then go to [teensy keys](https://www.pjrc.com/teensy/td_keyboard.html) and look for your keys combination.

Place them inside of:
<pre lang="arduino"><code>    
    if (name_of_your_button.risingEdge()){
      //Send keystrokes
    }
</code></pre>
