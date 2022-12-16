from pyo import *
import wave

kGAIN = 20

s = Server().boot()
src = Sine()

out = Sig(src, mul=kGAIN)
disType = input("What distortion type do you want, 1 or 2?\n") 

# Setting and Performing distortion
if disType == 1:
  if out > 1 or out < -1:
    out = out + ((out**3)/3)
if disType == 2:
  if out > 1:
    out = 1
  elif out < -1:
    out = -1

# attenuate volume
out = (out * .0045)
# set to output 
out = out.out(2)

s.gui(locals())

Compress()