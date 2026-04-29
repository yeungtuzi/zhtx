//stone.c
//by masterall

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"致歉"RED"信"NOR , ({ "letter" }) );
        set_weight(600);
        set("value",0);
        set("long", HIY"这是一封纵横天下II巫师组全体成员给玩家的致歉信，
用精美的信封包着，看来确有诚意的说，还不赶紧打开(read letter)看看？\n"NOR);
        if( clonep() )
                set_default_object(__FILE__);   
                set("unit", "封");
                set("no_get", 1);
                set("no_drop", 1);
                set("no_give", 1);
                set("no_sell", 1);
                set("no_paimai", 1);
                set("no_put", 1);
                set("unpawnable", 1);
       
}

void init()
{
       add_action("do_read","read");
}

int do_read()
{
         object me,ob;
         int exp,luck;
         me = this_player();
         ob = this_object();
         exp = me->query("combat_exp");
         luck = random(me->query("kar"));

         if (exp < 50000)
               return notify_fail("你好像是新手吧，这封信和你关系不大还是别看了。\n");

         if (me->query("have_read") )
               return notify_fail("你已经看过信了，还是踏踏实实玩游戏吧。\n");
 
         tell_object(me,HIY"由于服务器主机网络调整，机房从同方大厦换到了新的科技广场，\n"NOR);
         tell_object(me,HIY"导致了整个游戏停顿瘫痪近半个月，我们对此深表歉意。\n"NOR);
         tell_object(me,HIY"今后还希望您能一如既往的支持我们的工作，关注和投入这个游戏。\n"NOR);
         tell_object(me,HIY"为补偿您在此期间苦苦等待所受的损失和煎熬，特给予您：\n"NOR);
         me->set("have_read",1);

         if( exp < 12800000)
         {
         me->add("combat_exp", 1280000);
         me->add("potential", 680000);
         me->add("wlshw",30);
         tell_object(me,HIG"战斗经验值增加1280000点，"NOR);
         tell_object(me,HIG"潜能增加680000点，"NOR);
         tell_object(me,HIG"武林声望增加30点，\n"NOR);
         tell_object(me,HIY"的回报。\n"NOR);

         }

         if( exp >= 12800000)
         {
         me->add("combat_exp", exp/10);
         me->add("potential", 680000);
         me->add("wlshw",50);
         tell_object(me,HIG"战斗经验值增加10％，"NOR);
         tell_object(me,HIG"潜能增加680000点，"NOR);
         tell_object(me,HIG"武林声望增加50点，\n"NOR);
         tell_object(me,HIY"的回报。\n"NOR);
         }

         if( luck > 25 )
         {
         me->add("cor", 1);
         me->add("cps", 1);
         me->add("int", 1);
         me->add("lea", 1);
         me->add("dex", 1);
         me->add("bln", 1);
         me->add("con", 1);
         me->add("str", 1);
         me->add("per", 1);
         me->add("kar", 1);
         me->add("spi", 1);
         me->add("leo", 1);
         me->add("msc", 1);
         me->add("wil", 1);
         me->add("vis", 1);
         if(me->query("bln") > 50) me->set("bln", 50);
         tell_object(me,HIW"另外还特别恭喜您中了此次活动的大奖，提升所有天赋各一点！\n"NOR);
         }

       destruct(this_object());
               return 1;

}
