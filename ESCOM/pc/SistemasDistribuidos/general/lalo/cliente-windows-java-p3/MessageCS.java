import java.nio.ByteBuffer;
import java.nio.ByteOrder;


public class MessageCS {

    private  int opcode;    
    private  int count;
    private  int offset;
    private  String name;
    private final int BUF_SIZE = 1000;
    
    public MessageCS(int opcoud, int caunt, int ofset, String neim){
        this.opcode = opcoud;
        this.count = caunt;
        this.offset = ofset;
        this.name = neim;
    }
/*  
    public byte[] getByteRepr() {
        ByteBuffer bb = ByteBuffer.allocate(4 * Integer.BYTES + BUF_SIZE);
        bb.order(ByteOrder.LITTLE_ENDIAN);
        bb.putInt(this.opcode);
        bb.putInt(this.count);
        bb.putInt(this.offset);
        bb.put(name);
        return bb.array();
    }*/

    public byte[] getByteRepr() {
        ByteBuffer bb = ByteBuffer.allocate(4 * Integer.BYTES + 255);
        bb.order(ByteOrder.LITTLE_ENDIAN);
        bb.putInt(this.opcode);
        bb.putInt(this.count); 
        bb.putInt(this.offset);                               
        for (int i = 0; i < this.name.length(); i++)
          bb.put((byte) this.name.charAt(i));
        return bb.array();
    }

    public int getOpcode() { 
        return opcode; 
    }

    public int getCount() { 
        return count; 
    }
    
    public int getOffset() { 
        return offset; 
    }

    public String getName() { 
        return name; 
    }
    
    public void setOpcode(int opcoud) { 
        opcode = opcoud;
    }

    public void setCount(int caunt) { 
        count = caunt; 
    }    

    public void setOffset(int ofset) {
        offset = ofset; 
    }

    public void setName(String neim) { 
        name = neim;
    }

}
