def kertolasku(num1, num2):
    # initialize variables
    bitmask = 1
    output = 0
    bitshifted_num1 = num1
    remaining = num2
    while(remaining != 0):
        # read a bit using bitmask
        variable = num2
        variable = bitmask & variable
        if(variable != 0):
            # add bitshifted_num1 to output
            output = bitshifted_num1 + output
    
    # process remaining
        if(remaining & bitmask != 0):
            # remove processed bit from remaining
            remaining =  remaining - bitmask
    # bitshift bitmask and bitshifted_num1
        # increment bitmask
        bitmask = bitmask + bitmask
        # bitshift num1
        bitshifted_num1 = bitshifted_num1 + bitshifted_num1
        
       
        
    return output

if __name__ == "__main__":
    for i in range(1,100):
        for j in range(1,100):
            print(f"num1: {i}, num2: {j}")
            assert(kertolasku(i,j) == i*j)