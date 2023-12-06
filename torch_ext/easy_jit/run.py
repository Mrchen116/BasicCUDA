import torch
from torch.utils.cpp_extension import load

ext_module = load(name="dog",  sources=["demo.cu"], verbose=True)
print("Module directory: ", ext_module.__file__)
x = torch.arange(0, 10, dtype=torch.int).reshape(2, 5)
ext_module.print_array(x)
