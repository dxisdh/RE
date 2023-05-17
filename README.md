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
Mở source code lên, ta thấy ở trong hàm checkPassword có câu lệnh if kiểm tra xem độ dài của password có bằng 32 hay không. Tiếp theo ta khai báo kiểu char cho biến buffer để lưu các kí tự. Tại vòng for đầu tiên, i chạy từ 0 cho đến 7 và 
[vault-door-3]: `picoCTF{jU5t_a_s1mpl3_an4gr4m_4_u_79958f}`
[vault-door-4]: `picoCTF{jU5t_4_bUnCh_0f_bYt3s_8f_4a6cbf3b}`
[vault-door-5]: `picoCTF{c0nv3rt1ng_fr0m_ba5e_64_e3152bf4}`
[vault-door-6]: `picoCTF{n0t_mUcH_h4rD3r_tH4n_x0r_948b888}`
[vault-door-7]: `picoCTF{A_b1t_0f_b1t_sh1fTiNg_dc80e28124}`
[Transformation]: `picoCTF{picoCTF{16_bits_inst34d_of_8_04c0760d}`
[keygenme-py]: `picoCTF{1n_7h3_|<3y_of_54ef6292}`
[crackme-py]: `picoCTF{1|\/|_4_p34|\|ut_dd2c4616}`
[bloat.py]: `picoCTF{d30bfu5c4710n_f7w_b8062eec}`
