
# coding: utf-8

# In[1]:

from pynq import Overlay
from pynq.iop import Pmod_ADC, Pmod_DAC


# In[2]:

ol = Overlay('base.bit')
ol.download()


# In[3]:

from pynq.iop import PMODA,PMODB
adc = Pmod_ADC(PMODA)
dac = Pmod_DAC(PMODB)


# In[4]:

SawToothWaveGen(1)


# In[4]:

dac.write(0.35)
sample = adc.read()
print(sample)


# In[22]:

import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
get_ipython().magic('matplotlib notebook')
fig, ax = plt.subplots()

x = np.arange(0, 2*np.pi, 0.01)
line, = ax.plot(x, np.sin(x))


def init():  # only required for blitting to give a clean slate.
    line.set_ydata([np.nan] * len(x))
    return line,


def animate(i):
    line.set_ydata(np.sin(x + i / 100))  # update the data.
    return line,


ani = animation.FuncAnimation(
    fig, animate, init_func=init, interval=2, blit=True, save_count=50)

# To save the animation, use e.g.
#
# ani.save("movie.mp4")
#
# or
#
# from matplotlib.animation import FFMpegWriter
# writer = FFMpegWriter(fps=15, metadata=dict(artist='Me'), bitrate=1800)
# ani.save("movie.mp4", writer=writer)

plt.show()


# In[12]:

import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
get_ipython().magic('matplotlib notebook')
fig, ax = plt.subplots()
xdata, ydata = [], []
ln, = ax.plot([], [], 'r-', animated=False)

def init():
    ax.set_xlim(0, 2*np.pi)
    ax.set_ylim(-1, 1)
    return ln,

def update(frame):
    xdata.append(frame)
    ydata.append(np.sin(frame))
    ln.set_data(xdata, ydata)
    return ln,

ani = FuncAnimation(fig, update, frames=np.linspace(0, 2*np.pi, 128),
                    init_func=init, blit=True)
plt.show()


# In[7]:

from pynq import Overlay
from pynq.iop import Pmod_ADC, Pmod_DAC
ol = Overlay('base.bit')
ol.download()
from pynq.iop import PMODA,PMODB
adc = Pmod_ADC(PMODA)
dac = Pmod_DAC(PMODB)

sample = adc.read()
y=dac.write(sample[0])
print(y)


# In[16]:

from math import ceil
from time import sleep
import numpy as np
import matplotlib.pyplot as plt
from pynq.lib import Pmod_ADC, Pmod_DAC
from pynq.overlays.base import BaseOverlay

ol = BaseOverlay("base.bit")

dac = Pmod_DAC(ol.PMODB)
adc = Pmod_ADC(ol.PMODA)

delay = 0.0
values = np.linspace(0, 2, 20)
samples = []
for value in values:
    dac.write(value)
    sleep(delay)
    sample = adc.read()
    samples.append(sample[0])
    print('Value written: {:4.2f}\tSample read: {:4.2f}\tError: {:+4.4f}'.
          format(value, sample[0], sample[0]-value))
get_ipython().magic('matplotlib inline')
    
X = np.arange(len(values))
plt.bar(X + 0.0, values, facecolor='blue', 
        edgecolor='white', width=0.5, label="Written_to_DAC")
plt.bar(X + 0.25, samples, facecolor='red', 
        edgecolor='white', width=0.5, label="Read_from_ADC")

plt.title('DAC-ADC Linearity')
plt.xlabel('Sample_number')
plt.ylabel('Volts')
plt.legend(loc='upper left', frameon=False)

plt.show()


# In[3]:

from math import ceil
from time import sleep
import time
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
from pynq import Overlay
from pynq.iop import Pmod_ADC, Pmod_DAC
ol = Overlay('base.bit')
ol.download()
adc = Pmod_ADC(1)
dac = Pmod_DAC(2)
delay = 0.0
input_volt = 1
neg = 0 
samples = []
x = np.arange(0,10*np.pi,0.01)
error = 0

get_ipython().magic('matplotlib notebook')
fig, ax = plt.subplots()

xdata, ydata = [], []



for i in range(2 , 3 , 1):
    
    print(i) 
    ln, = ax.plot(x, abs(np.sin(x*input_volt*i)), 'r-', animated=False)
    ln1, = ax.plot(x, abs(np.sin(x*input_volt*i)), 'b-', animated=False)
    
    def init():
        ax.set_xlim(0, 2*np.pi,3)
        ax.set_ylim(-1.05, 1.05)
        ln.set_ydata([np.nan] * len(x))
        ln1.set_ydata([np.nan] * len(x))
        return ln1,
        return ln,
    t_start=time.time()
    for j in x:
        if(j > (2*np.pi/i)):
            j = j%(2*np.pi/i)
        if(j > (np.pi/i)):
            neg = 1
        if(j < (np.pi/i)):
            neg = 0
        dac.write(abs(np.sin(i*input_volt*j)))
        sleep(delay)
        sample = adc.read()
        if(neg==1):
            sample[0] = -sample[0]
        samples.append(sample[0])
#         print('Value written: {:4.2f}\t{:4.2f}\tSample read: {:4.2f}\tError: {:+4.4f}'.
#               format(value, np.sin(i*value*j), sample[0], abs(sample[0])-np.sin(i*value*j)))
        k = abs(np.sin(i*input_volt*j))-abs(sample[0])
        if(error < abs(k)):
            error = abs(k)
    t_end=time.time()
    def update(frame):
        ln.set_ydata(np.sin(i*x+(frame/2)))
        ln1.set_ydata(samples)
        ln1.set_xdata(x-(frame/2/i))
        return ln1,
        return ln,

#     samples = []
    print(error)
    print('it spends ',t_end-t_start ,'sec')
    ani = FuncAnimation(fig, update,frames=np.linspace(0, 10*np.pi, 400),init_func=init, interval=2, blit=True, save_count=100) 
    fig.set_size_inches(6, 4)
    plt.show()


# In[13]:

from math import ceil
from time import sleep
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
from pynq import Overlay
from pynq.iop import Pmod_ADC, Pmod_DAC
ol = Overlay('base.bit')
ol.download()
adc = Pmod_ADC(1)
dac = Pmod_DAC(2)
delay = 0.0
input_volt = 1
neg = 0 
samples = []
yy = []
x = np.arange(0,2*np.pi,0.01)

get_ipython().magic('matplotlib notebook')
fig, ax = plt.subplots()
xdata, ydata = [], []



for i in range(1 , 2 , 1):
    
    print(i) 
    ln, = ax.plot(x, abs(np.sin(x*input_volt*i)), 'r-', animated=False)
    ln1, = ax.plot(x, abs(np.sin(x*input_volt*i)), 'r-', animated=False)
    
    def init():
        ax.set_xlim(0, 2*np.pi)
        ax.set_ylim(-1.05, 1.05)
        ln.set_ydata([np.nan] * len(x))
        ln1.set_ydata([np.nan] * len(x))
        return ln1,
        return ln,
    
    for j in x:
        if(j > (2*np.pi/i)):
            j = j%(2*np.pi/i)
        if(j > (np.pi/i)):
            neg = 1
        if(j < (np.pi/i)):
            neg = 0
        dac.write(abs(np.sin(i*input_volt*j)))
        sleep(delay)
        sample = adc.read()
        if(neg==1):
            sample[0] = -sample[0]
        samples.append(sample[0])
#         print('Value written: {:4.2f}\t{:4.2f}\tSample read: {:4.2f}\tError: {:+4.4f}'.
#               format(value, np.sin(i*value*j), sample[0], abs(sample[0])-np.sin(i*value*j)))

    def update(frame):

        ln.set_ydata(np.sin(i*x+(frame/2)))
        ln1.set_ydata(samples)
        ln1.set_xdata(x-(frame/2/i))
        return ln1,
        return ln,

#     samples = []

    ani = FuncAnimation(fig, update,frames=np.linspace(0, 10*np.pi, 450),init_func=init, interval=2, blit=True, save_count=100) 
    plt.show()


# In[ ]:



