import java.nio.ByteBuffer;
import java.nio.ByteOrder;

public class MensajeServidorCliente {
    
    private final int BUF_SIZE = 1000;

    private int count;   
    private int result;    
    private byte[] data;    

    public MensajeServidorCliente(int c, int r, byte[] d){
        count = c;
        result = r;
        data = d;        
    }
    
    public byte[] getByteRepr(){
        ByteBuffer buffer = ByteBuffer.allocate(3 * Integer.BYTES + BUF_SIZE);
        buffer.order(ByteOrder.LITTLE_ENDIAN);
        buffer.putInt(count);
        buffer.putInt(result);                                
        for(int i = 0; i < BUF_SIZE; i++)
          buffer.put(data[i]);
        return buffer.array();
    }
    
    public int getCount(){ 
        return count;
    }

    public int getResult(){  
        return result; 
    }

    public byte[] getData(){ 
        return data; 
    }

    public void setCount(int c){ 
        count = c;
    }

    public void setResult(int r){ 
        result = d;
    }

    public void setData(byte[] d){ 
        data = d;
    }

}
