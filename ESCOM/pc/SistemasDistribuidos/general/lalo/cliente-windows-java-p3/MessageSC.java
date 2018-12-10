import java.nio.ByteBuffer;
import java.nio.ByteOrder;

public class MessageSC {
    
    private int count;   
    private int result;    
    private String data; 
    private  int offset;   
    

    public MessageSC(int count, int result, String data, int offset){
        this.count = count;
        this.result =  result;
        this.data = data;   
        this.offset = offset;     
    }
    
    public static MessageSC getClassFromBytes(byte[] buf) {
        ByteBuffer bb = ByteBuffer.wrap(buf);
        bb.order(ByteOrder.LITTLE_ENDIAN);

        int opcoud = bb.getInt();
        int caunt = bb.getInt();
        int ofset = bb.getInt();
        StringBuilder sb = new StringBuilder();
        
        byte nameByte;
        while ( (nameByte = bb.get()) != '\0' )
            sb.append((char) nameByte);
        
        MessageSC mensaje = new MessageSC(opcoud, caunt, sb.toString(), ofset);

        return mensaje;
    }
/*
    public byte[] getByteRepr() {
        ByteBuffer bb = ByteBuffer.allocate(4 * Integer.BYTES + 255);
        bb.order(ByteOrder.LITTLE_ENDIAN);
        bb.putInt(this.count);
        bb.putInt(this.result); 
        bb.putInt(this.offset);                               
        for (int i = 0; i < this.data.length(); i++)
          bb.put((byte) this.data.charAt(i));
        return bb.array();
    }
/*
    public byte[] getByteRepr() {
        ByteBuffer bb = ByteBuffer.allocate(3 * Integer.BYTES + 255);
        bb.order(ByteOrder.LITTLE_ENDIAN);
        bb.putInt(opcode);
        bb.putInt(count);
        bb.putInt(offset);
        for (int i = 0; i < name.length(); i++)
          bb.put((byte) name.charAt(i));
        return bb.array();
    }
  */  
    public int getCount() { 
        return count;
    }

    public int getResult() { 
        return result; 
    }

    public String getData() { 
        return data; 
    }

    public int getOffset() { 
        return offset; 
    }

    public void setCount(int caunt) { 
        count = caunt;
    }

    public void setResult(int res) { 
        result = res;
    }

    public void setData(String dat) { 
        data = dat;
    }

    public void setOffset(int ofset) { 
        offset = ofset;
    }

}
