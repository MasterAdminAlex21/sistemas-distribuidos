import java.nio.ByteBuffer;
import java.nio.ByteOrder;

public class MensajeServidorCliente {
    
    private final int BUF_SIZE = 1000;

    private int count;   
    private int result;
    private int offset;
    private byte[] data;    

    public MensajeServidorCliente(){
        count = 0;
        result = 0;
        offset = 0;
        data = new byte[BUF_SIZE];
    }

    public MensajeServidorCliente(int c, int r, int o, byte[] d){
        count = c;
        result = r;
        data = d;
        offset = o;
    }
    
    public byte[] getByteRepr(){
        ByteBuffer buffer = ByteBuffer.allocate(4 * Integer.BYTES + BUF_SIZE);

        buffer.order(ByteOrder.LITTLE_ENDIAN);
        buffer.putInt(count);
        buffer.putInt(result);                 
        buffer.putInt(offset);
        for(int i = 0; i < data.length; i++)
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

    public int getOffset(){
        return offset;
    }

    public void setCount(int c){ 
        count = c;
    }

    public void setResult(int r){ 
        result = r;
    }

    public void setData(byte[] d){ 
        data = d;
    }

    public void setOffset(int o){
        offset = o;
    }
}
