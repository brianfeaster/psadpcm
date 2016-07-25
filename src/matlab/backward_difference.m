classdef backward_difference < handle
% backward difference filter.  y(n) = x(n) - x(n-1).
    
   properties
       lastValue = 0;
   end
   
   methods
       function delta = filter(obj, newValue)
           delta = newValue - obj.lastValue;
           obj.lastValue = newValue;
       end
       
       function reset(obj)
           obj.lastValue = 0;
       end
   end
    
end