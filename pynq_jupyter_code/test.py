
# coding: utf-8

# In[1]:

from pynq import Overlay
from pynq.board import LED
from pynq.board import RGBLED
from pynq.board import Switch
from pynq.board import Button

Overlay("base.bit").download()


# In[2]:

led0 = LED(0)


# In[3]:

import time
from pynq.board import LED
from pynq.board import Button

led0 = LED(0)
for i in range(20):
    led0.toggle()
    time.sleep(.3)

