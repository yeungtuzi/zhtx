// welcomed.c
// Created by dongsw@zhtx2 2002.8
// Change the welcome to welcomed.c can use #include <ansi.h>

#include <ansi.h>

inherit F_SAVE;
inherit F_DBASE;

void create()
{
        seteuid(getuid());
        restore();
}
void show_welcome()
{
        string str;
        object me = this_player();

        str = REF"\n\n\n\n                           "BGRN"  "NOR HIG" 纵横天下 II"BGRN"  "NOR"\n\n";
        str +=HIY"\n                To Venture In A New World With Great Case\n\n"NOR;
        str +=BRED"                                                                         \n"NOR;
        str +=YEL"\n           请选择适合您的地址连线以达到最嘉效果\n"NOR;
        str +="\n           "YEL"本站地址"NOR"     < www.my6868.com >         6688   "YEL"[永久域名]"NOR"\n";
        str +="                        < 211.101.171.57 >         6688   "YEL"[主力地址]"NOR"\n";
        str +="                        < 211.68.29.81   >         6688   "YEL"[教育网用]"NOR"\n";
        str +="           "YEL"ZHI地址"NOR "      < 159.226.41.165 >         6868\n\n"NOR;
          str +=YEL"           主页地址 "HIG"    http://home.cd200.com/dongsw   "BLINK HIR"[已开通]\n"NOR;
        str +=YEL"\n           泥巴论坛 "NOR"    < http://zhtx2bbs.yeah.net >\n"NOR;
        str +="                        < telnet:bbs.ncic.ac.cn >\n"NOR;
        str +=YEL"\n           站务信箱 "NOR"    < dongsiw@sohu.com >     \n"NOR;
        str +=RED"──────────────────────────────────────────\n\n\n"NOR;


        write(str);
}



