# RE
Writeup bài tập RE

#### vault-door-training

Your mission is to enter Dr. Evil's laboratory and retrieve the blueprints for his Doomsday Project. The laboratory is protected by a series of locked vault doors. Each door is controlled by a computer and requires a password to open. Unfortunately, our undercover agents have not been able to obtain the secret passwords for the vault doors, but one of our junior agents obtained the source code for each vault's computer! You will need to read the source code for each level to figure out what the password is for that vault door. As a warmup, we have created a replica vault in our training facility. The source code for the training vault is here: 
```
import java.util.*;

class VaultDoorTraining {
    public static void main(String args[]) {
        VaultDoorTraining vaultDoor = new VaultDoorTraining();
        Scanner scanner = new Scanner(System.in); 
        System.out.print("Enter vault password: ");
        String userInput = scanner.next();
	String input = userInput.substring("picoCTF{".length(),userInput.length()-1);
	if (vaultDoor.checkPassword(input)) {
	    System.out.println("Access granted.");
	} else {
	    System.out.println("Access denied!");
	}
   }

    // The password is below. Is it safe to put the password in the source code?
    // What if somebody stole our source code? Then they would know what our
    // password is. Hmm... I will think of some ways to improve the security
    // on the other doors.
    //
    // -Minion #9567
    public boolean checkPassword(String password) {
        return password.equals("w4rm1ng_Up_w1tH_jAv4_be8d9806f18");
    }
}
```
#### Solution
Mở source code lên, ta thấy flag nằm tại hàm checkPassword:
```
public boolean checkPassword(String password) {
        return password.equals("w4rm1ng_Up_w1tH_jAv4_be8d9806f18");
    }
```
Flag: `picoCTF{w4rm1ng_Up_w1tH_jAv4_be8d9806f18}`
#### vault-door-1

This vault uses some complicated arrays! I hope you can make sense of it, special agent. The source code for this vault is here: 
```
import java.util.*;

class VaultDoor1 {
    public static void main(String args[]) {
        VaultDoor1 vaultDoor = new VaultDoor1();
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter vault password: ");
	String userInput = scanner.next();
	String input = userInput.substring("picoCTF{".length(),userInput.length()-1);
	if (vaultDoor.checkPassword(input)) {
	    System.out.println("Access granted.");
	} else {
	    System.out.println("Access denied!");
	}
    }

    // I came up with a more secure way to check the password without putting
    // the password itself in the source code. I think this is going to be
    // UNHACKABLE!! I hope Dr. Evil agrees...
    //
    // -Minion #8728
    public boolean checkPassword(String password) {
        return password.length() == 32 &&
               password.charAt(0)  == 'd' &&
               password.charAt(29) == '9' &&
               password.charAt(4)  == 'r' &&
               password.charAt(2)  == '5' &&
               password.charAt(23) == 'r' &&
               password.charAt(3)  == 'c' &&
               password.charAt(17) == '4' &&
               password.charAt(1)  == '3' &&
               password.charAt(7)  == 'b' &&
               password.charAt(10) == '_' &&
               password.charAt(5)  == '4' &&
               password.charAt(9)  == '3' &&
               password.charAt(11) == 't' &&
               password.charAt(15) == 'c' &&
               password.charAt(8)  == 'l' &&
               password.charAt(12) == 'H' &&
               password.charAt(20) == 'c' &&
               password.charAt(14) == '_' &&
               password.charAt(6)  == 'm' &&
               password.charAt(24) == '5' &&
               password.charAt(18) == 'r' &&
               password.charAt(13) == '3' &&
               password.charAt(19) == '4' &&
               password.charAt(21) == 'T' &&
               password.charAt(16) == 'H' &&
               password.charAt(27) == '5' &&
               password.charAt(30) == '2' &&
               password.charAt(25) == '_' &&
               password.charAt(22) == '3' &&
               password.charAt(28) == '0' &&
               password.charAt(26) == '7' &&
               password.charAt(31) == 'e';
    }
}
```
#### Solution
Mở source code lên, tại hàm checkPassword sẽ trả lại giá trị của password có độ dài là 32 và chưa được sắp xếp theo thứ tự. Ta viết chương trình sắp xếp lại các kí tự:
```
#include<iostream>
using namespace std;

int main()
{
	char flag[32];
	string s = "picoCTF{";
	flag[0] = 'd'; 
	flag[29] = '9';
	flag[4] = 'r';
	flag[2] = '5';
	flag[23] = 'r';
	flag[3] = 'c';
	flag[17] = '4';
	flag[1] = '3';
	flag[7] = 'b';
	flag[10] = '_';
	flag[5] = '4';
	flag[9] = '3';
	flag[11] = 't';
	flag[15] = 'c';
	flag[8] = 'l';
	flag[12] = 'H';
	flag[20] = 'c';
	flag[14] = '_';
	flag[6] = 'm';
	flag[24] = '5';
	flag[18] = 'r';
	flag[13] = '3';
	flag[19] = '4';
	flag[21] = 'T';
	flag[16] = 'H';
	flag[27] = '5';
	flag[30] = '2';
	flag[25] = '_';
	flag[22] = '3';
	flag[28] = '0';
	flag[26] = '7';
	flag[31] = 'e';
	for(int i = 0; i <= 31;i++)
	{
		s += flag[i];
	}
	s += "}";
	cout << s;
	return 0;
}
```
Flag: `picoCTF{d35cr4mbl3_tH3_cH4r4cT3r5_75092e}`
#### vault-door-3
This vault uses for-loops and byte arrays. The source code for this vault is here: 
```
import java.util.*;

class VaultDoor3 {
    public static void main(String args[]) {
        VaultDoor3 vaultDoor = new VaultDoor3();
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter vault password: ");
        String userInput = scanner.next();
	String input = userInput.substring("picoCTF{".length(),userInput.length()-1);
	if (vaultDoor.checkPassword(input)) {
	    System.out.println("Access granted.");
	} else {
	    System.out.println("Access denied!");
        }
    }

    // Our security monitoring team has noticed some intrusions on some of the
    // less secure doors. Dr. Evil has asked me specifically to build a stronger
    // vault door to protect his Doomsday plans. I just *know* this door will
    // keep all of those nosy agents out of our business. Mwa ha!
    //
    // -Minion #2671
    public boolean checkPassword(String password) {
        if (password.length() != 32) {
            return false;
        }
        char[] buffer = new char[32];
        int i;
        for (i=0; i<8; i++) {
            buffer[i] = password.charAt(i);
        }
        for (; i<16; i++) {
            buffer[i] = password.charAt(23-i);
        }
        for (; i<32; i+=2) {
            buffer[i] = password.charAt(46-i);
        }
        for (i=31; i>=17; i-=2) {
            buffer[i] = password.charAt(i);
        }
        String s = new String(buffer);
        return s.equals("jU5t_a_sna_3lpm18g947_u_4_m9r54f");
    }
}
```
#### Solution
Mở source code lên, ta thấy ở trong hàm checkPassword có câu lệnh if kiểm tra xem độ dài của password có bằng 32 hay không. Tiếp theo ta khai báo kiểu char cho biến buffer để lưu các kí tự. Ta thực hiện việc sắp xếp trật tự các kí tự ở trong xâu: `jU5t_a_sna_3lpm18g947_u_4_m9r54f`. Tại vòng lặp đầu tiên, 8 kí tự đầu không thay đổi vị trí được lưu vào buffer. Tại vòng lặp thứ hai, i chạy từ 8 đến 15 và các kí tự được lưu vào buffer với trật tự sắp xếp là 23 - i. Tại vòng lặp thứ ba, i chạy từ 16 đến 31 và tăng lần lượt 2 kí tự và các kí tự được lưu vào buffer với trật tự sắp xếp là 46 - i. Tại vòng lặp cuối cùng, i chạy từ 31 đến 17 và giảm lần lưượt và vị trí không thay đổi.

Ta viết chương trình sắp xếp lại xâu:
```
#include<iostream>
using namespace std;

int main()
{
	char flag[32] = "";
	string s = "jU5t_a_sna_3lpm18g947_u_4_m9r54f";
	for(int i = 0; i < 8; i++)
	flag[i] = s[i];
	for(int i = 8; i < 16; i++)
	flag[i] = s[23 - i];
	for(int i = 16; i < 32; i += 2)
	flag[i] = s[46 - i];
	for(int i = 31; i >= 17; i -= 2)
	flag[i] = s[i];
	cout << flag;
	return 0;
}
```
Flag: `picoCTF{jU5t_a_s1mpl3_an4gr4m_4_u_79958f}`
#### vault-door-4
This vault uses ASCII encoding for the password. The source code for this vault is here:
```
import java.util.*;

class VaultDoor4 {
    public static void main(String args[]) {
        VaultDoor4 vaultDoor = new VaultDoor4();
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter vault password: ");
        String userInput = scanner.next();
	String input = userInput.substring("picoCTF{".length(),userInput.length()-1);
	if (vaultDoor.checkPassword(input)) {
	    System.out.println("Access granted.");
	} else {
	    System.out.println("Access denied!");
        }
    }

    // I made myself dizzy converting all of these numbers into different bases,
    // so I just *know* that this vault will be impenetrable. This will make Dr.
    // Evil like me better than all of the other minions--especially Minion
    // #5620--I just know it!
    //
    //  .:::.   .:::.
    // :::::::.:::::::
    // :::::::::::::::
    // ':::::::::::::'
    //   ':::::::::'
    //     ':::::'
    //       ':'
    // -Minion #7781
    public boolean checkPassword(String password) {
        byte[] passBytes = password.getBytes();
        byte[] myBytes = {
            106 , 85  , 53  , 116 , 95  , 52  , 95  , 98  ,
            0x55, 0x6e, 0x43, 0x68, 0x5f, 0x30, 0x66, 0x5f,
            0142, 0131, 0164, 063 , 0163, 0137, 070 , 0146,
            '4' , 'a' , '6' , 'c' , 'b' , 'f' , '3' , 'b' ,
        };
        for (int i=0; i<32; i++) {
            if (passBytes[i] != myBytes[i]) {
                return false;
            }
        }
        return true;
    }
}
```
#### Solution
Mở source code lên, ta thấy flag có độ dài là 32. Tại mảng myBytes, ta thấy 8 số đầu tiên thuộc hệ thập phân, 8 số tiếp theo thuộc hệ thập lục phân, 8 số tiếp theo thuộc mã ASCII và 8 kí tự cuối. Ta viết chương trình để giải mã như sau:
```
passBytes = [None] * 32
myBytes = [
            106 , 85  , 53  , 116 , 95  , 52  , 95  , 98  ,
            '0x55', '0x6e', '0x43', '0x68', '0x5f', '0x30', '0x66', '0x5f',
            '0o142', '0o131', '0o164', '0o63' , '0o163', '0o137', '0o70' , '0o146',
            '4' , 'a' , '6' , 'c' , 'b' , 'f' , '3' , 'b' ,
	    ]

for i in range(0,8):
	passBytes[i] =  chr(myBytes[i])
for i in range(8,16):
	passBytes[i] =  chr(int(myBytes[i], 16))
for i in range(16,24):
	passBytes[i] =  chr(int(myBytes[i], 8))
for i in range(24,32):
	passBytes[i] =  myBytes[i]
	
print("picoCTF{{{}}}".format(''.join(passBytes)))
```
Flag: `picoCTF{jU5t_4_bUnCh_0f_bYt3s_8f_4a6cbf3b}`
#### vault-door-5
In the last challenge, you mastered octal (base 8), decimal (base 10), and hexadecimal (base 16) numbers, but this vault door uses a different change of base as well as URL encoding! The source code for this vault is here:
```
import java.net.URLDecoder;
import java.util.*;

class VaultDoor5 {
    public static void main(String args[]) {
        VaultDoor5 vaultDoor = new VaultDoor5();
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter vault password: ");
        String userInput = scanner.next();
	String input = userInput.substring("picoCTF{".length(),userInput.length()-1);
	if (vaultDoor.checkPassword(input)) {
	    System.out.println("Access granted.");
	} else {
	    System.out.println("Access denied!");
        }
    }

    // Minion #7781 used base 8 and base 16, but this is base 64, which is
    // like... eight times stronger, right? Riiigghtt? Well that's what my twin
    // brother Minion #2415 says, anyway.
    //
    // -Minion #2414
    public String base64Encode(byte[] input) {
        return Base64.getEncoder().encodeToString(input);
    }

    // URL encoding is meant for web pages, so any double agent spies who steal
    // our source code will think this is a web site or something, defintely not
    // vault door! Oh wait, should I have not said that in a source code
    // comment?
    //
    // -Minion #2415
    public String urlEncode(byte[] input) {
        StringBuffer buf = new StringBuffer();
        for (int i=0; i<input.length; i++) {
            buf.append(String.format("%%%2x", input[i]));
        }
        return buf.toString();
    }

    public boolean checkPassword(String password) {
        String urlEncoded = urlEncode(password.getBytes());
        String base64Encoded = base64Encode(urlEncoded.getBytes());
        String expected = "JTYzJTMwJTZlJTc2JTMzJTcyJTc0JTMxJTZlJTY3JTVm"
                        + "JTY2JTcyJTMwJTZkJTVmJTYyJTYxJTM1JTY1JTVmJTM2"
                        + "JTM0JTVmJTYzJTMxJTM0JTYzJTYzJTY1JTMxJTMx";
        return base64Encoded.equals(expected);
    }
}
```
#### Solution
Mở source code lên, ta thấy ở hàm checkPassword sẽ trả về một xâu kí tự sau khi xâu `expected` được giải mã Base64:
```
 public boolean checkPassword(String password) {
        String urlEncoded = urlEncode(password.getBytes());
        String base64Encoded = base64Encode(urlEncoded.getBytes());
        String expected = "JTYzJTMwJTZlJTc2JTMzJTcyJTc0JTMxJTZlJTY3JTVm"
                        + "JTY2JTcyJTMwJTZkJTVmJTYyJTYxJTM1JTY1JTVmJTM2"
                        + "JTM0JTVmJTYzJTMxJTM0JTYzJTYzJTY1JTMxJTMx";
        return base64Encoded.equals(expected);
    }
```
Ta sẽ viết chương trình giải mã như sau:
```
import base64

expected = "JTYzJTMwJTZlJTc2JTMzJTcyJTc0JTMxJTZlJTY3JTVmJTY2JTcyJTMwJTZkJTVmJTYyJTYxJTM1JTY1JTVmJTM2JTM0JTVmJTYzJTMxJTM0JTYzJTYzJTY1JTMxJTMx"
base64_bytes = expected.encode("ascii")
  
expected_bytes = base64.b64decode(base64_bytes)
base64_string = expected_bytes.decode("ascii")

base64_string = base64_string.replace('%', ' 0x')
ch = base64_string.split(" ")

print('picoCTF{', end = '')
for c in ch:
	if(c != ''):
		print(chr(int(c, 16)), end = '')
			
print('}')
```
Flag: `picoCTF{c0nv3rt1ng_fr0m_ba5e_64_e3152bf4}`
#### vault-door-6
This vault uses an XOR encryption scheme. The source code for this vault is here:
```
import java.util.*;

class VaultDoor6 {
    public static void main(String args[]) {
        VaultDoor6 vaultDoor = new VaultDoor6();
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter vault password: ");
        String userInput = scanner.next();
	String input = userInput.substring("picoCTF{".length(),userInput.length()-1);
	if (vaultDoor.checkPassword(input)) {
	    System.out.println("Access granted.");
	} else {
	    System.out.println("Access denied!");
        }
    }

    // Dr. Evil gave me a book called Applied Cryptography by Bruce Schneier,
    // and I learned this really cool encryption system. This will be the
    // strongest vault door in Dr. Evil's entire evil volcano compound for sure!
    // Well, I didn't exactly read the *whole* book, but I'm sure there's
    // nothing important in the last 750 pages.
    //
    // -Minion #3091
    public boolean checkPassword(String password) {
        if (password.length() != 32) {
            return false;
        }
        byte[] passBytes = password.getBytes();
        byte[] myBytes = {
            0x3b, 0x65, 0x21, 0xa , 0x38, 0x0 , 0x36, 0x1d,
            0xa , 0x3d, 0x61, 0x27, 0x11, 0x66, 0x27, 0xa ,
            0x21, 0x1d, 0x61, 0x3b, 0xa , 0x2d, 0x65, 0x27,
            0xa , 0x6c, 0x61, 0x6d, 0x37, 0x6d, 0x6d, 0x6d,
        };
        for (int i=0; i<32; i++) {
            if (((passBytes[i] ^ 0x55) - myBytes[i]) != 0) {
                return false;
            }
        }
        return true;
    }
}
```
#### Solution
Mở source code lên, tại hàm checkPassword, ta biết được độ dài flag là 32 và được giải mã bằng phép toán XOR. Ta viết chương trình giải mã như sau:
```
passBytes = [None] * 32
myBytes = [
            0x3b, 0x65, 0x21, 0xa , 0x38, 0x0 , 0x36, 0x1d,
            0xa , 0x3d, 0x61, 0x27, 0x11, 0x66, 0x27, 0xa ,
            0x21, 0x1d, 0x61, 0x3b, 0xa , 0x2d, 0x65, 0x27,
            0xa , 0x6c, 0x61, 0x6d, 0x37, 0x6d, 0x6d, 0x6d,
        ]

for i in range(32):
	passBytes[i] =  chr(myBytes[i] ^ 0x55)

print("picoCTF{{{}}}".format(''.join(passBytes)))
```
Flag: `picoCTF{n0t_mUcH_h4rD3r_tH4n_x0r_948b888}`
#### vault-door-7
This vault uses bit shifts to convert a password string into an array of integers. Hurry, agent, we are running out of time to stop Dr. Evil's nefarious plans! The source code for this vault is here:
```
import java.util.*;
import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;
import java.security.*;

class VaultDoor7 {
    public static void main(String args[]) {
        VaultDoor7 vaultDoor = new VaultDoor7();
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter vault password: ");
        String userInput = scanner.next();
	String input = userInput.substring("picoCTF{".length(),userInput.length()-1);
	if (vaultDoor.checkPassword(input)) {
	    System.out.println("Access granted.");
	} else {
	    System.out.println("Access denied!");
        }
    }

    // Each character can be represented as a byte value using its
    // ASCII encoding. Each byte contains 8 bits, and an int contains
    // 32 bits, so we can "pack" 4 bytes into a single int. Here's an
    // example: if the hex string is "01ab", then those can be
    // represented as the bytes {0x30, 0x31, 0x61, 0x62}. When those
    // bytes are represented as binary, they are:
    //
    // 0x30: 00110000
    // 0x31: 00110001
    // 0x61: 01100001
    // 0x62: 01100010
    //
    // If we put those 4 binary numbers end to end, we end up with 32
    // bits that can be interpreted as an int.
    //
    // 00110000001100010110000101100010 -> 808542562
    //
    // Since 4 chars can be represented as 1 int, the 32 character password can
    // be represented as an array of 8 ints.
    //
    // - Minion #7816
    public int[] passwordToIntArray(String hex) {
        int[] x = new int[8];
        byte[] hexBytes = hex.getBytes();
        for (int i=0; i<8; i++) {
            x[i] = hexBytes[i*4]   << 24
                 | hexBytes[i*4+1] << 16
                 | hexBytes[i*4+2] << 8
                 | hexBytes[i*4+3];
        }
        return x;
    }

    public boolean checkPassword(String password) {
        if (password.length() != 32) {
            return false;
        }
        int[] x = passwordToIntArray(password);
        return x[0] == 1096770097
            && x[1] == 1952395366
            && x[2] == 1600270708
            && x[3] == 1601398833
            && x[4] == 1716808014
            && x[5] == 1734304867
            && x[6] == 942695730
            && x[7] == 942748212;
    }
}
```
#### Solution
Mở source code lên, tại phần comment đã gợi ý cách mã hóa từng kí tự trong flag thành số. Đầu tiên ta sẽ chuyển từng kí tự sang dạng hệ thập lục phân, sau đó chuyển sang dạng nhị phân. Và nếu ta đặt 4 số nhị phân 8 bit cạnh nhau, ta sẽ có một số có 32 bit, tức là dạng số nguyên. Tại hàm checkPassword, ta biết được flag có độ dài 32 và các số ở mảng x chính là các chuỗi kí tự đã được mã hóa theo cách trên. Ta có chương trình giải mã như sau:
```
x = [0] * 8

x[0] = 1096770097
x[1] = 1952395366
x[2] = 1600270708
x[3] = 1601398833
x[4] = 1716808014
x[5] = 1734304867
x[6] = 942695730
x[7] = 942748212

ch = [None] * 4
buffer = ""

for i in range(0,8):
	tmp = str(bin(x[i])[2:].zfill(32))
	ch[0] = chr(int(hex(int(tmp[:8], 2)), 16))
	ch[1] = chr(int(hex(int(tmp[8:16], 2)), 16))
	ch[2] = chr(int(hex(int(tmp[16:24], 2)), 16))
	ch[3] = chr(int(hex(int(tmp[24:32], 2)), 16))
	buffer += ch[0] + ch[1] + ch[2] + ch[3]

print("picoCTF{{{}}}".format(buffer))
```
Flag: `picoCTF{A_b1t_0f_b1t_sh1fTiNg_dc80e28124}`
#### Transformation
I wonder what this really is... enc ''.join([chr((ord(flag[i]) << 8) + ord(flag[i + 1])) for i in range(0, len(flag), 2)])

enc = 灩捯䍔䙻ㄶ形楴獟楮獴㌴摟潦弸弰㑣〷㘰摽
#### Solution
Ta thây đoạn code trên cho biết rằng mỗi kí tự trong flag được di chuyển sang trái 8 bit sau đó thêm kí tự đằng sau và chuyển sang dạng ASCII. Ta viết chương trình dịch ngược lại đoạn code trên:
```
enc = '灩捯䍔䙻ㄶ形楴獟楮獴㌴摟潦弸弰㑣〷㘰摽'
output = ''
for i in range(len(enc)):
    output += chr(ord(enc[i])>>8) + chr((ord(enc[i])) - ((ord(enc[i])>>8) <<8))
print(output)
```
Flag: `picoCTF{16_bits_inst34d_of_8_04c0760d}`
#### keygenme-py
```
#============================================================================#
#============================ARCANE CALCULATOR===============================#
#============================================================================#

import hashlib
from cryptography.fernet import Fernet
import base64



# GLOBALS --v
arcane_loop_trial = True
jump_into_full = False
full_version_code = ""

username_trial = "PRITCHARD"
bUsername_trial = b"PRITCHARD"

key_part_static1_trial = "picoCTF{1n_7h3_|<3y_of_"
key_part_dynamic1_trial = "xxxxxxxx"
key_part_static2_trial = "}"
key_full_template_trial = key_part_static1_trial + key_part_dynamic1_trial + key_part_static2_trial

star_db_trial = {
  "Alpha Centauri": 4.38,
  "Barnard's Star": 5.95,
  "Luhman 16": 6.57,
  "WISE 0855-0714": 7.17,
  "Wolf 359": 7.78,
  "Lalande 21185": 8.29,
  "UV Ceti": 8.58,
  "Sirius": 8.59,
  "Ross 154": 9.69,
  "Yin Sector CL-Y d127": 9.86,
  "Duamta": 9.88,
  "Ross 248": 10.37,
  "WISE 1506+7027": 10.52,
  "Epsilon Eridani": 10.52,
  "Lacaille 9352": 10.69,
  "Ross 128": 10.94,
  "EZ Aquarii": 11.10,
  "61 Cygni": 11.37,
  "Procyon": 11.41,
  "Struve 2398": 11.64,
  "Groombridge 34": 11.73,
  "Epsilon Indi": 11.80,
  "SPF-LF 1": 11.82,
  "Tau Ceti": 11.94,
  "YZ Ceti": 12.07,
  "WISE 0350-5658": 12.09,
  "Luyten's Star": 12.39,
  "Teegarden's Star": 12.43,
  "Kapteyn's Star": 12.76,
  "Talta": 12.83,
  "Lacaille 8760": 12.88
}


def intro_trial():
    print("\n===============================================\n\
Welcome to the Arcane Calculator, " + username_trial + "!\n")    
    print("This is the trial version of Arcane Calculator.")
    print("The full version may be purchased in person near\n\
the galactic center of the Milky Way galaxy. \n\
Available while supplies last!\n\
=====================================================\n\n")


def menu_trial():
    print("___Arcane Calculator___\n\n\
Menu:\n\
(a) Estimate Astral Projection Mana Burn\n\
(b) [LOCKED] Estimate Astral Slingshot Approach Vector\n\
(c) Enter License Key\n\
(d) Exit Arcane Calculator")

    choice = input("What would you like to do, "+ username_trial +" (a/b/c/d)? ")
    
    if not validate_choice(choice):
        print("\n\nInvalid choice!\n\n")
        return
    
    if choice == "a":
        estimate_burn()
    elif choice == "b":
        locked_estimate_vector()
    elif choice == "c":
        enter_license()
    elif choice == "d":
        global arcane_loop_trial
        arcane_loop_trial = False
        print("Bye!")
    else:
        print("That choice is not valid. Please enter a single, valid \
lowercase letter choice (a/b/c/d).")


def validate_choice(menu_choice):
    if menu_choice == "a" or \
       menu_choice == "b" or \
       menu_choice == "c" or \
       menu_choice == "d":
        return True
    else:
        return False


def estimate_burn():
  print("\n\nSOL is detected as your nearest star.")
  target_system = input("To which system do you want to travel? ")

  if target_system in star_db_trial:
      ly = star_db_trial[target_system]
      mana_cost_low = ly**2
      mana_cost_high = ly**3
      print("\n"+ target_system +" will cost between "+ str(mana_cost_low) \
+" and "+ str(mana_cost_high) +" stone(s) to project to\n\n")
  else:
      # TODO : could add option to list known stars
      print("\nStar not found.\n\n")


def locked_estimate_vector():
    print("\n\nYou must buy the full version of this software to use this \
feature!\n\n")


def enter_license():
    user_key = input("\nEnter your license key: ")
    user_key = user_key.strip()

    global bUsername_trial
    
    if check_key(user_key, bUsername_trial):
        decrypt_full_version(user_key)
    else:
        print("\nKey is NOT VALID. Check your data entry.\n\n")


def check_key(key, username_trial):

    global key_full_template_trial

    if len(key) != len(key_full_template_trial):
        return False
    else:
        # Check static base key part --v
        i = 0
        for c in key_part_static1_trial:
            if key[i] != c:
                return False

            i += 1

        # TODO : test performance on toolbox container
        # Check dynamic part --v
        if key[i] != hashlib.sha256(username_trial).hexdigest()[4]:
            return False
        else:
            i += 1

        if key[i] != hashlib.sha256(username_trial).hexdigest()[5]:
            return False
        else:
            i += 1

        if key[i] != hashlib.sha256(username_trial).hexdigest()[3]:
            return False
        else:
            i += 1

        if key[i] != hashlib.sha256(username_trial).hexdigest()[6]:
            return False
        else:
            i += 1

        if key[i] != hashlib.sha256(username_trial).hexdigest()[2]:
            return False
        else:
            i += 1

        if key[i] != hashlib.sha256(username_trial).hexdigest()[7]:
            return False
        else:
            i += 1

        if key[i] != hashlib.sha256(username_trial).hexdigest()[1]:
            return False
        else:
            i += 1

        if key[i] != hashlib.sha256(username_trial).hexdigest()[8]:
            return False



        return True


def decrypt_full_version(key_str):

    key_base64 = base64.b64encode(key_str.encode())
    f = Fernet(key_base64)

    try:
        with open("keygenme.py", "w") as fout:
          global full_version
          global full_version_code
          full_version_code = f.decrypt(full_version)
          fout.write(full_version_code.decode())
          global arcane_loop_trial
          arcane_loop_trial = False
          global jump_into_full
          jump_into_full = True
          print("\nFull version written to 'keygenme.py'.\n\n"+ \
                 "Exiting trial version...")
    except FileExistsError:
    	sys.stderr.write("Full version of keygenme NOT written to disk, "+ \
	                  "ERROR: 'keygenme.py' file already exists.\n\n"+ \
			  "ADVICE: If this existing file is not valid, "+ \
			  "you may try deleting it and entering the "+ \
			  "license key again. Good luck")

def ui_flow():
    intro_trial()
    while arcane_loop_trial:
        menu_trial()



# Encrypted blob of full version
full_version = \
b"""
gAAAAABgT_nvf4P0-CFwlBsPrO8lFGYdOMPOsW49NMCVP4OQm4TqUiwWH6wolWNozf6wSudqEnLxlV6_tpyRrEDHQjBf05wp3N8eVOlkGtbYvQ1j3rJp5A-u68f04WfV-Tbx87qMXkicUYywezrlklzxOtOGeqatlaT9uQXVHu9FyZbYmcKGrpQ5gnGc-u278DYd2vmYgo8Y4gsf0DsRy3R3OhpI9oAYBtoThP6A2kwvggWAYUTNv6VQ3mcpwgwGqJP6tro8BHkGJVW2xQMiptJfXWdANIAQOoL9Xse3spqlSmnaZzTZ2nGpWtzPsGXXbBo2YRV1tRm4HNeS4VpSnHPVd5nNBe7hTckqs_ye1WkG58z1ldo7fvLDRudVMrjBYSsQHd64XMaq5KFZeKWtm0F6r5DYK5d5UFhZzZi8F7PIQZ481lgTb4QxBu0HvsMcjk9r10aeKHzMxYDEpq8o9xZXlBhYMB9N6919y2Deuk2-VICbc2RX5NMzBjIfqnwJvWG7w8ystaiN-BxATHHcvSuV6_3tsGqEbJi7wILo2sMBiAa_a3pLDnIovXhG3dqbxR0Ay9fQFSJvcUqqbyXcK5MPs52_iZWJ2wD27ac6EQP911pHwaE6N_7p3u8zHOzMk4LDSZJhADeotihRJYXuAw3laDfOVWo1H2JoLGfuU6--4PcJAqQz1ZRTXWEkP6hcd2UtXKZVF8kzGTRyl5KSbMoU2ZJGSXrVZMpjdFE5WON_ZBa-TAdw537NZvr-bVINw8oPmb39n3VYRQFB_bkuUHcgHqVaexTIrAVL10jJdyIQtVRaZdxWkmdhNNWgkhSXozz9oatq_PYVlb_6aiWD8co4l019-H8dhrZHqMUR06JryR3aDcV85eFKSQKWfs5gS67vJYfPj3V7SJVUtS30jGEjZQO8mmBnncBOX927pBxZKtwn111m9Ryr-Lwack7UWQj4JFIDgHwXghN7ScGQDc3BNQImfutCuVFf9MVOCb7QZru0icd7o3eEztFDPHOZQIKSDBq7zfmZBgppEFZjouAUO4d97hkcnSGf6nRM2oqhwt_9N5h_e3SntRNJGoPfHrjsWutGZO-2kaw6kFIVsL0QBdMDS2V8oFFCpMiNoWS1OvrILvzT-UGtQKtfmC0H-zR1CL3PQGfPbcgW08EmkuSPrZk-bKTucvz6r_9PxQPMznyhpm_5f1MhYt_eKkwpkRS9zChuNtb3vP2Qp3M5CUdWpxA3dNmrarihWka94RCuUDftROcBIWpNUrWci-fkDCzeYHwFs_qH3DK85dKpmQVnmHrrRG2rH9Y1jW2jpqmEHiZKjc6tQa2kmRVR9vDvaygFjDAzGk7b2h7nLFHCKPvJnvkw-yvSIL8GVHVTWhe2PhK983qu2RQIlL3R-27Xzx_pz_0OehnosqeZkY19T1Jzri2BcL9HYB_qAdniXONU36zj9ZiUs_Ffpq4OgiVw2-bBLIDEtpN2xSj2P7-An_Xjtbgr0ukMdEUjFLV4yScjaqDBM7kM1rE2l4fFPY0pEMy3aasIAJRL9mDS04jLDCsZn_BxxIlOpnVBvHZld_rRyRWtbN3UESj6jl2pHIxzgvMg9E8Eyt8XT7bgRfimMDrocMahrGhE018t3xTNDtNHgnoaD2t4DyqQr1pr6TcMKRxNqqXy3dEYvKDVhBmzFc00YKkT6bp0ufwpzlknFnEEmHh6QAoxdM5uD_3QEm1X67gtwoOXFtY3TSGJ9CzfWsOeQ_BjxyWJkm4W6b3SbnlJ68hsTXUk6Cc3uzoczgwCeyb6uSw5O9cHT-s5KTpHlnISkB0SYs4pZMHcQ-gq3URPYTeGP11KLfWCMuznCosYc3R7jriReKKOjFD2CU2Fc-i_CmlkRJ4tqDhKZFx3UhBCUQY4JVAOS8RQTb1T9qW-mNe8JcDEpPirqNMI_wL3EFWKyd8jQGM38mRjkq2p2jf9HRNVvmpyFNWxiOP8jsG3RvtiGS3Nv58D417EgRUCG_FEQiHRKmxjuUIAmpGEioln2Yf3sGYoBfvhwlZinTdpiVoUwjRAZdRXMvoYhRQnIT7ykQlTax64DS4RxHeFjaO6FyWMR3rDkRQSvMsUTzmFGVST564CfvSUHKPIz91SNcgbQoR5Y3-4GS50qX87sBu8ow-Z6zquzMDavkpBJzxrB1NX0Tez1SREt4ViK3Hi5Jvr1r8uKTDgjH62v5HBRZlqlMOQBXPBKAAMPUOqqsqKbil6NOiOADezhcYfc4Vy3N11AfL3mx2AIHpLfdtYcUzsuImPpAu6V75_zD5GdzGdb-N3uYPJrkKmQOoK61HsJQjVjgluoNHavR13fJ0FQWYJpEyn4P1Tuhkv4pgtYMtiXHwC6804DdsTMdgFrTR3K0E-xwDq0E68pkcebW7hZAuXE3Qhxviyb6BHx5E_recW3q2Od7_J_CSiECgf_0ykLuKZM4aQBLp7UM9aafK109Z6rwGDdsJ3_C5u0RIZ6gh5d_lRtWroUzsTryuM-XqRe_xuIbLzYBeAqSjovbKFIeev3vJ3KdNRVO65kBJUaOIGn7uv6Qv2am4Hfo-wu86J2wKyMaAUsL0TEyKKInh03rg1IQY84xdAEeqVSStn3fU5GdnxYrt-ByhvTNAoXhGGKPjzhzLdvgBB07Or9OtjvjyDByD8KFpolp1_TiMnDW6Rp66HQlqFgqgrEA0Ix3-nkU_R2yC8xR2QEvD2A9JxKKwc03NtwmlKi9NlslYKLS0g7lu3CombAx7AqAMIF__kM8czRVV9Np-IvDp2CZEArvryF_Oo0CKszZy2ngXZbSD1bobYDa6168yUNGyaL-nbDiB28QL1wiDjLL6vF-dYU2Q9-cVuE11bSZOzbARbr-oaMHC6QACNbs6vpF6Tq9tOJdEbUfAwXt-BEk3KlAW7mcYgpFvADD6ZdefN99lCoAJSljgy243CMEfw8WGfNUMh8uHKsmcHie089aiJLlzEs5o0MacV43ttbgBQ0rMD7e5KHf56dqDO0k15E9UsYsiniGbs8sNPRL-SQzpZqWBd4z2gEXc9_l7xMv_GpXBz4Dj7OJKu7TzD5Vvmd54wqWcMPo7MMIpMY6xyUIZgK9IvUc_dRkV9ze3FfaJi656TBo4Fw1MgURqyRx8kCUsMCqGJgftryPMA0iA0ha3_9dEIZKyJwt51I1JltO6GUQTMYa9nvmcbFyxH3XIgjjT2T8X1vrPZqYDJ0BMIV1OlweD_V69NjykDxa879r-SvSByONyeTrqe_yDfBKxjVJPPmSy9U9uIN8mjuPOjbHnnG_vjsACp22slbyv5Qc75znhhwQe7KuxCIuf3WfZi_WDMXxWKXaaM-Q4o8qM5B3Ak2lC1VyalFvUkLA-aUTrj1RgQ6FziAA14l9cQQu4hJJ0mOBdmcAd_cpbCkD2ADlA-IxYcIXflwDWf-WUO8b-QzuHie3g0V6dzlCN9B56w6XlwhkeTS4OQdmtIBVZvhqBXJpXzmHBLlHwirF4COCWSn5w_Q7D9z1kq0RjMyzqrq36UTVGjKfWxMKVvnd1RQkn3PsddwJG62Dfaty3td43RyTUvsGwrTglZWe7v6229eYxDXwmgbtJ_eWSjdcyr9i38diyOLbDzs6xvdLL4bjR5WqB4YBcNFlXMvnyJxt4hiyDvZriJpmtsa7O58-ReW4KkbDo1RjrL20GeFfiQELW_V-11gvPoyLIigmTt4oluCleUDLuZ0gkhRLY9ve9f8kmQDsMLWSM2S-0xq4Q3QQZrOAHYEme3o5iROA2EU5lYwQGXXJIiVsIYzQWC2ULrmqJ67ceCwUgPzdCT8qnnhTETGwGDxFlLbJRiiqpNQ3WeGgEHFSN2bLQypC5CZwowIg==
"""



# Enter main loop
ui_flow()

if jump_into_full:
    exec(full_version_code)
```
#### Solution
Mở source code lên, ta thấy key sẽ được tạo thành bởi key_part_static1_trial, key_part_static1_trial và key_part_static2_trial. Ta chỉ cần tìm key_part_static1_trial là hoàn thành flag. Tại hàm check_key sẽ kiểm tra xem chiều dài của key có bằng chiều dài của key_full_template_trial và ta sẽ bắt đầu với xâu key_part_static1_trial. Phần này có username được đưa đầu chương trình và mã hóa bằng thuật toán SHA256 và được biểu diễn dưới dạng một kí tự hex và được sắp xếp theo vị trí. Ta có chương trình tìm key_part_static1_trial như sau:
```
import hashlib
import base64

Username_trial = b"PRITCHARD"

key_part = "picoCTF{1n_7h3_|<3y_of_"
user = hashlib.sha256(Username_trial).hexdigest()

key_part += user[4]
key_part += user[5]
key_part += user[3]
key_part += user[6]
key_part += user[2]
key_part += user[7]
key_part += user[1]
key_part += user[8]
key_part += "}"

print(key_part)
```
Flag: `picoCTF{1n_7h3_|<3y_of_54ef6292}`
#### crackme-py
```
# Hiding this really important number in an obscure piece of code is brilliant!
# AND it's encrypted!
# We want our biggest client to know his information is safe with us.
bezos_cc_secret = "A:4@r%uL`M-^M0c0AbcM-MFE055a4ce`eN"

# Reference alphabet
alphabet = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ"+ \
            "[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~"



def decode_secret(secret):
    """ROT47 decode

    NOTE: encode and decode are the same operation in the ROT cipher family.
    """

    # Encryption key
    rotate_const = 47

    # Storage for decoded secret
    decoded = ""

    # decode loop
    for c in secret:
        index = alphabet.find(c)
        original_index = (index + rotate_const) % len(alphabet)
        decoded = decoded + alphabet[original_index]

    print(decoded)



def choose_greatest():
    """Echo the largest of the two numbers given by the user to the program

    Warning: this function was written quickly and needs proper error handling
    """

    user_value_1 = input("What's your first number? ")
    user_value_2 = input("What's your second number? ")
    greatest_value = user_value_1 # need a value to return if 1 & 2 are equal

    if user_value_1 > user_value_2:
        greatest_value = user_value_1
    elif user_value_1 < user_value_2:
        greatest_value = user_value_2

    print( "The number with largest positive magnitude is "
        + str(greatest_value) )



choose_greatest()
```
Mở source code lên, ta thấy hàm decode_secret sẽ thực hiện thuật toán giải mã ROT-47. Ta dùng tool giải mã ROT-47 là tìm được flag.
Flag: `picoCTF{1|\/|_4_p34|\|ut_dd2c4616}`
#### bloat-py
```
import sys
a = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ"+ \
            "[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~ "
def arg133(arg432):
  print(a[71]+a[64]+a[79]+a[79]+a[88]+a[66]+a[71]+a[64]+a[77]+a[66]+a[68])
  if arg432 == a[71]+a[64]+a[79]+a[79]+a[88]+a[66]+a[71]+a[64]+a[77]+a[66]+a[68]:
    return True
  else:
    print(a[51]+a[71]+a[64]+a[83]+a[94]+a[79]+a[64]+a[82]+a[82]+a[86]+a[78]+\
a[81]+a[67]+a[94]+a[72]+a[82]+a[94]+a[72]+a[77]+a[66]+a[78]+a[81]+\
a[81]+a[68]+a[66]+a[83])
    sys.exit(0)
    return False
def arg111(arg444):
  return arg122(arg444.decode(), a[81]+a[64]+a[79]+a[82]+a[66]+a[64]+a[75]+\
a[75]+a[72]+a[78]+a[77])
def arg232():
  return input(a[47]+a[75]+a[68]+a[64]+a[82]+a[68]+a[94]+a[68]+a[77]+a[83]+\
a[68]+a[81]+a[94]+a[66]+a[78]+a[81]+a[81]+a[68]+a[66]+a[83]+\
a[94]+a[79]+a[64]+a[82]+a[82]+a[86]+a[78]+a[81]+a[67]+a[94]+\
a[69]+a[78]+a[81]+a[94]+a[69]+a[75]+a[64]+a[70]+a[25]+a[94])
def arg132():
  return open('flag.txt.enc', 'rb').read()
def arg112():
  print(a[54]+a[68]+a[75]+a[66]+a[78]+a[76]+a[68]+a[94]+a[65]+a[64]+a[66]+\
a[74]+a[13]+a[13]+a[13]+a[94]+a[88]+a[78]+a[84]+a[81]+a[94]+a[69]+\
a[75]+a[64]+a[70]+a[11]+a[94]+a[84]+a[82]+a[68]+a[81]+a[25])
def arg122(arg432, arg423):
    arg433 = arg423
    i = 0
    while len(arg433) < len(arg432):
        arg433 = arg433 + arg423[i]
        i = (i + 1) % len(arg423)        
    return "".join([chr(ord(arg422) ^ ord(arg442)) for (arg422,arg442) in zip(arg432,arg433)])
arg444 = arg132()
arg432 = arg232()
arg133(arg432)
arg112()
arg423 = arg111(arg444)
print(arg423)
sys.exit(0)
```
#### Solution
Mở source code lên, ta thấy chương trình có vẻ đã bị obfuscate. Ta chú ý đoạn sau:
```
def arg133(arg432):
  if arg432 == a[71]+a[64]+a[79]+a[79]+a[88]+a[66]+a[71]+a[64]+a[77]+a[66]+a[68]:
    return True
  else:
    print(a[51]+a[71]+a[64]+a[83]+a[94]+a[79]+a[64]+a[82]+a[82]+a[86]+a[78]+\
a[81]+a[67]+a[94]+a[72]+a[82]+a[94]+a[72]+a[77]+a[66]+a[78]+a[81]+\
a[81]+a[68]+a[66]+a[83])
    sys.exit(0)
    return False
```
Ta thấy nếu arg432 == a[71]+a[64]+a[79]+a[79]+a[88]+a[66]+a[71]+a[64]+a[77]+a[66]+a[68] thì ta sẽ nhận được cụm `happychance`, còn nếu không thì sẽ chương trình sẽ in ra `password is incorrect`. Ta nhập vào webshell của pico: `python3 bloat.py`, sau đó ta sẽ cần nhập password là happychance và nhận được flag
Flag: `picoCTF{d30bfu5c4710n_f7w_b8062eec}`
