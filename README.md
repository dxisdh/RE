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
Mở source code lên, tại hàm checkPassword sẽ trả lại giá trị của password có độ dài là 32 và chưa được sắp xếp theo thứ tự. Ta viết chương trình C++ sắp xếp lại các kí tự:
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
Mở source code lên, ta thấy ở trong hàm checkPassword có câu lệnh if kiểm tra xem độ dài của password có bằng 32 hay không. Tiếp theo ta khai báo kiểu char cho biến buffer để lưu các kí tự. Ta thực hiện việc sắp xếp trật tự các kí tự ở trong xâu: `jU5t_a_sna_3lpm18g947_u_4_m9r54f`. Tại vòng lặp đầu tiên, 8 kí tự đầu không thay đổi vị trí được lưu vào buffer. Tại vòng lặp thứ hai, i chạy từ 8 đến 15 và các kí tự được lưu vào buffer với trật tự sắp xếp là 23 - i. Tại vòng lặp thứ ba, i chạy từ 16 đến 31 và tăng lần lượt 2 kí tự và các kí tự được lưu vào buffer với trật tự sắp xếp là 46 - i. Tại vòng lặp cuối cùng, i chạy từ 31 đến 17 và giảm lần lưượt và vị trí không thay đổi.

Ta viết chương trình sắp xếp lại xâu:
``
buffer = [None] * 32
password = 'jU5t_a_sna_3lpm18g947_u_4_m9r54f'

for i in range(0,8):
 	buffer[i] = password[i]

for i in range(8,16):
     	buffer[i] = password[23-i]

for i in range(16,32,2):
     	buffer[i] = password[46-i]

for i in range(31,16,-2):
     	buffer[i] = password[i]

print("picoCTF{{{}}}".format(''.join(buffer)))
``
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
Mở source code lên, ta thấy flag có độ dài là 32. Tại mảng myBytes, ta thấy 8 số đầu tiên thuộc hệ thập phân, 8 số tiếp theo thuộc hệ thập lục phân, 8 số tiếp theo thuộc mã ASCII và 8 kí tự cuối. Ta dùng tool decode hệ thập phân, hệ thập lục phân và chuyển mã ASCII. Ta dùng mảng passBytes dùng để nối các kí tự ở mảng myBytes. Cuối cùng ta thu được flag.
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
Mở source code lên, ta thấy ở hàm checkPassword sẽ trả về một xâu kí tự. 
[vault-door-5]: `picoCTF{c0nv3rt1ng_fr0m_ba5e_64_e3152bf4}`
[vault-door-6]: `picoCTF{n0t_mUcH_h4rD3r_tH4n_x0r_948b888}`
[vault-door-7]: `picoCTF{A_b1t_0f_b1t_sh1fTiNg_dc80e28124}`
[Transformation]: `picoCTF{picoCTF{16_bits_inst34d_of_8_04c0760d}`
[keygenme-py]: `picoCTF{1n_7h3_|<3y_of_54ef6292}`
[crackme-py]: `picoCTF{1|\/|_4_p34|\|ut_dd2c4616}`
[bloat.py]: `picoCTF{d30bfu5c4710n_f7w_b8062eec}`
