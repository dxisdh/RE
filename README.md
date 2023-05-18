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

[Transformation]: `picoCTF{picoCTF{16_bits_inst34d_of_8_04c0760d}`
[keygenme-py]: `picoCTF{1n_7h3_|<3y_of_54ef6292}`
[crackme-py]: `picoCTF{1|\/|_4_p34|\|ut_dd2c4616}`
[bloat.py]: `picoCTF{d30bfu5c4710n_f7w_b8062eec}`
