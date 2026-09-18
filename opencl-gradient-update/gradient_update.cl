__kernel void gradient_update(__global float *gradients, __global float *inputs, __global float *weights, int M)
{
    int i = get_global_id(0);    
    weights[i] += gradients[i / M] * inputs[i % M];
}



