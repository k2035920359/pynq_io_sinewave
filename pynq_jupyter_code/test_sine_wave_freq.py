
# coding: utf-8

# In[ ]:

from pynq.iop import Pmod_ADC, Pmod_DAC
from pynq.iop import PMODA,PMODB
adc = Pmod_ADC(PMODA)
dac = Pmod_DAC(PMODB)

from math import ceil
from time import sleep
import numpy as np

adc = Pmod_ADC(1)
dac = Pmod_DAC(2)

x=np.arange(0,2*np.pi,0.1)

while(1):
    y=adc.read()
    print(y[0])
    for i in x:
        dac.write(np.sin(2*y[0]*i)+1)
        k = dac.write(np.sin(0.1*y[0]*i)+1)
#         print(k)


# In[ ]:




# In[ ]:




# In[ ]:




# In[ ]:

from pynq import Overlay
from pynq.iop import Pmod_ADC, Pmod_DAC
# ol = Overlay('base.bit')
# ol.download()

from pynq.iop import PMODA,PMODB
adc = Pmod_ADC(PMODA)
dac = Pmod_DAC(PMODB)

from math import ceil
from time import sleep
import numpy as np
import matplotlib.pyplot as plt

adc = Pmod_ADC(1)
dac = Pmod_DAC(2)

x=np.arange(0,2*np.pi,0.1)

# for j in range(10):
# print(y[0])

while(1):
    y=adc.read()
    print(y[0])
    for i in x:
        dac.write(1)
#         k=dac.write(np.sin(y[0]*i)+1)
#         print(k)
# dac.write(abs(np.sin(0.01*y[0]*i)))  #if np.sin(y[0]*i) out of the output range , +1(shift 1)

# dac.write(0.35)
# sample = adc.read()
# print(sample)


# In[ ]:



