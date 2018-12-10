import java.nio.ByteBuffer;
import java.nio.ByteOrder;


public class MensajeClienteServidor {

    private int opcode;    
    private int count;
    private int offset;
    private String name;
    
    public MensajeClienteServidor(){
        opcode = 0;
        count = 0;
        offset = 0;
        name = "";
    }

    public MensajeClienteServidor(int o, int c, int off, String n){
        opcode = o;
        count = c;
        offset = off;
        name = n;
    }
    
    public static MensajeClienteServidor getClassFromBytes(byte[] data) {
        ByteBuffer buffer = ByteBuffer.wrap(data);

        buffer.order(ByteOrder.LITTLE_ENDIAN);
        int auxOpcode = buffer.getInt();
        int auxCount = buffer.getInt();
        int auxOff = buffer.getInt();

        StringBuilder stringData = new StringBuilder();
        byte nameByte;

        while ( (nameByte = buffer.get()) != '\0' )
            stringData.append((char) nameByte);
        
        MensajeClienteServidor mensaje = new MensajeClienteServidor(auxOpcode, auxCount, auxOff, stringData.toString());

        return mensaje;
    }
    
    public byte[] getByteRepr() {
        ByteBuffer buffer = ByteBuffer.allocate(3 * Integer.BYTES + 255);

        buffer.order(ByteOrder.LITTLE_ENDIAN);
        buffer.putInt(opcode);
        buffer.putInt(count);
        buffer.putInt(offset);
        for (int i = 0; i < name.length(); i++)
          buffer.put((byte) name.charAt(i));

        return buffer.array();
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
    
    public void setOpcode(int o) { 
        opcode = o;
    }

    public void setCount(int c) { 
        count = c; 
    }    

    public void setOffset(int o) {
        offset = o; 
    }

    public void setName(String n) { 
        name = n;
    }

}
