# ATU-Attendance

ATU Attendance was designed to modernize a method used in so many educational institutions. 
I created an attendance system using RFID (Radio Field Identification) technology to record 
attendance of students and display it on a website to the teacher.


## Description

This project is an attendance system which will improve a day-to-day process that every school 
uses, roll call. My goal was to make this task as automated as possible by making roll call done 
by students just swiping a tag. I decided on this idea because I see in both school and 
University, we still use the basic method of pen and paper. A chance at modernizing this was a 
good project idea to me.

To achieve this, I relied heavily on RFID Technology (Radio Frequency Identification) and the 
versatility of the ESP32. RFID works by transmitting electromagnetic energy which hold 
information (the ‘ID’) from the tag to the reader. Although on a different end of the 
electromagnetic spectrum, it works the same as light does to our eyes, data sent to a reader 
which is then processed.

A basic explanation is this - a student will scan in their tag; this will show up on a website that 
only the teacher can access. They will be able to see who scanned in and who didn’t. After class 
ends the teacher clicks a button on the site and refreshes the currently shown attendance 
record.

There are also two other components which are for the end user’s sake, an LED and a Buzzer, 
these are just methods to tell them that their action has gone through and has been received

## Authors
  
[jAlbright02](https://github.com/jAlbright02)

## Acknowledgments

### Lecturers
+ Michelle Lynch
+ Brian O'Shea
+ Natasha Rohan

### Inspirations / Resources
[RFID Library used](https://github.com/miguelbalboa/rfid)
[Odin project](https://www.theodinproject.com/)
[Development Board used](https://www.espressif.com/en/products/socs/esp32)
