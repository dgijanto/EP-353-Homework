# Problem Set 5

Start Date and Time| Due Date and Time | Cut-off Date and Time |
---|---|---|
15:50:00 on November 16, 2022 | 14:00:00 on November 30, 2022 | 14:00:00 on December 7, 2021 |

\**Eastern Standard Time (EST) is used for dates and times with the 24-hour clock*

## Grading Rubric
Description|Grade
---|---:|
Submitted all problems | 10%
All programs have the correct names. | 10%
No compilation warning or error| 20%
Clean, understandable, commented, and organized | 20%
Correctly implemented | 40%
**Total** | **100%**

## Recommended Readings
- The Audio Programming Book
	- Ch. 3.4.3 and 3.4.4
- [Portaudio Documentation](http://files.portaudio.com/docs/v19-doxydocs/)

## Problem 5.1: Noise Gate
- Create a file named `Problem5.1.c` and use the `00.DAFxTemplate.c` to start this problem.
- Create a [noise gate effect](https://en.wikipedia.org/wiki/Noise_gate) that attenuates signals that register below the threshold of ±0.02.
- Use the `noisy.wav` as the sound source and save the result as `noisegate.wav`.
- Attached is an example of a noise gate effect applied to `noisy.wav` with the name `noisegate.wav`.

## Problem 5.2: Combining Effects
- Create a file named `Problem5.2.c` and use the `00.DAFxTemplate.c` to start this problem.
- Create an audio effect called fuzz-flanger based on the class materials provided for this week.
- Make sure to test your output audio file and observe that both fuzz and flanger are transforming the original audio data.
- Attached is an example of a fuzz-flanger effect on `Guitar.wav` with the name `FuzzFlanger.wav`.

## Problem 5.3: Bit Quantization/Reduction Effect
- Create a file named `Problem5.3.c` and use the `00.DAFxTemplate.c` to start this problem.
- Open `sine.wav` for signal processing.
- Implement the bit quantization/reduction effect documented [here](https://www.musicdsp.org/en/latest/Effects/96-bit-quantization-reduction-effect.html).
- The `keep_bits_from_16` function has two inputs. 
- The `short` data type, `input`, is the sample from a sound file.
- The `int` data type, `keepBits`, specifies how many bit reductions you want.
- The `keepBits` should be in the range of 1 ~ 16), and the lower the number, the more distorted the outcome will be.
- You will need to adjust the handling of an audio file with `libsndfile` according to how the `keep_bits_from_16` function works. 
- This means that you need to do it with shorts instead of processing audio data with floats.
- Save the result as `reduct.aiff` with 24-bit sound quality that demonstrates the resulting quantization/reduction effect.
- Attached is an example of a bit-quantization/reduction effect on `sine.wav` with the name `reduct.aiff`.

## Problem 5.4: Reverse Playback
- Create a file named `Problem5.4.c`.
- Based on `3.Playback/Playback.c`, modify the program to play an audio file in reverse order. 
- You must use `libsndfile` and `portaudio` for this problem set.
- Hit: You may want to load the entire audio data to an array before the playback.

## Problem 5.5: Distortion
- Create a file named `Problem5.5.c`.
- Based on `01.PassThrough.c`, modify the program to apply the hard-clipping distortion we covered in the Digital Audio Effects section.

--- 
**Berklee College of Music**  
Electronic Production and Design  
EP-353: Audio Programming in C  