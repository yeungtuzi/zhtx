// gift.c
// Modify By dongsw@zhtx2 2003

#include <ansi.h>

inherit F_CLEAN_UP;

string *gift_ranking = ({"极差","下等", "尚可", "平平", "良好", "优秀",
        "绝佳"});

string display_attr(int gift, int value);

string gift_evaluation(int raw,int value)
{
        int i;

        i = value / 5;
        if( i < 0 ) i = 0;
        if( i > 6 ) i = 6;
        if( value > raw )
                return HIC+gift_ranking[i]+NOR;
        if( value < raw )
                return HIY+gift_ranking[i]+NOR;
        return gift_ranking[i];

}


string gift_evaluation1(int raw,int value)
{
        string rank;

        if( value < 10 ) rank = "左手";
        else
                if( value > 20 ) rank = "右手";
        else
                rank = "均衡";

        if( value > raw )
                return HIC+rank+NOR;
        if( value < raw )
                return HIY+rank+NOR;
        return rank;

}

void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
        object ob;
        mapping my;
        string line;

        seteuid(getuid(me));

        if(!arg) ob = me;
        else {
                ob = present(arg, environment(me));
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
                if (!ob) return notify_fail("你要察看谁的天赋？\n");
                if (!wizardp(me) && !raw_wiz_level(me) && !ob->accept_info(me, "gift") )
                        return notify_fail("只有巫师能察看别人的天赋。\n");
        }

        my = ob->query_entire_dbase();

        line = ((ob == this_player()) ? ("您") : (ob->name())) + "的天赋状况如下：\n";
        line += HIG"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"NOR;
        line += HIG"先天天赋\n"NOR;
        line += HIG"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"NOR;
                line += sprintf(
                        " 胆识：[ %d ]  定力：[ %d ]  悟性：[ %d ]  统御：[ %d ]\n"
                        " 身法：[ %d ]  平衡：[ %d ]  体质：[ %d ]  力量：[ %d ]\n\n",

                        my["cor"],my["cps"],my["int"],my["lea"],
                        my["dex"],my["bln"],my["con"],my["str"]);
        line += HIG"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"NOR;
        line += HIG"后天天赋\n"NOR;                             
        line += HIG"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"NOR;
                line += sprintf(
                        " 胆识：[%s ]  定力：[%s ]  悟性：[%s ]  统御：[%s ]\n"
                        " 身法：[%s ]  平衡：[%s ]  体质：[%s ]  力量：[%s ]\n\n",

                        display_attr(my["cor"], ob->query_cor()),
                        display_attr(my["cps"], ob->query_cps()),
                        display_attr(my["int"], ob->query_int()),
                        display_attr(my["lea"], ob->query_lea()),
                        display_attr(my["dex"], ob->query_dex()),
                        display_attr(my["bln"], ob->query_bln()),
                        display_attr(my["con"], ob->query_con()),
                        display_attr(my["str"], ob->query_str()));
        line += HIG"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"NOR;                       
        line += HIG"隐藏天赋\n"NOR;                        
        line += HIG"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"NOR;
        line += HIG" 极差 < 下等 < 尚可 < 平平 < 良好 < 优秀 < 绝佳\n\n"NOR;
                line += sprintf(
                        " 魅力：[%s]  福缘：[%s]  偏好：[%s]  灵性：[%s]\n"
                        " 口才：[%s]  神秘：[%s]  意志：[%s]  远见：[%s]\n",

                        gift_evaluation(my["per"],ob->query_per()), gift_evaluation(my["kar"],ob->query_kar()),
                        gift_evaluation1(my["fav"],ob->query_fav()), gift_evaluation(my["spi"],ob->query_spi()),
                        gift_evaluation(my["elo"],ob->query_elo()),gift_evaluation(my["msc"],ob->query_msc()),
                        gift_evaluation(my["wil"],ob->query_wil()),gift_evaluation(my["vis"],ob->query_vis()));
        line += HIG"\n━━━━━━━━━━━━━━━━━━@ZHTX2━━━━━━━━━\n"NOR;

        write(line);

        return 1;
}

string display_attr(int gift, int value)
{
        if( value > gift ) return sprintf( HIY "%3d" NOR, value );
        else if( value < gift ) return sprintf( CYN "%3d" NOR, value );
        else return sprintf("%3d", value);
}


int help(object me)
{
        write(@HELP
指令格式
        gift
        gift <id> (for wizard)

        具体请查看 help gifts   

HELP
    );
    return 1;
}


