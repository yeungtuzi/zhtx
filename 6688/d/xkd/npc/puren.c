// shangshan.c 赏善使者
//by masterall
 
 
#include <ansi.h>
 
inherit NPC;

string ask_yuyi();
 
void consider();
 
void create()
{
        set_name("仆从", ({ "pu cong"}) );
 
        set("title", HIG "侠客岛"+HIY"接引使" NOR);
        set("gender", "男性");
        set("age", 40);
        set("long",
             "此人背手而立，目不斜视，但已经爆发出一阵阵的精芒。\n"
             "看来侠客岛上随随便便一个仆从的身手就可以踏入江湖一流高手的行列。\n"
        );
        set("attitude", "friendly");
        set("shen_type", 1);
        set("shen",3000000);
        set("str", 50);
        set("con", 50);
        set("int", 50);
        set("dex", 50);
        set("per", 30);
 
        set("force", 10000);
        set("max_force", 5000);
        set("force_factor", 250);
        set("max_kee", 5000);
        set("max_gin", 5000);
        set("max_sen", 5000);
 
        set("combat_exp", 50000000);
        set("score", 20000);

        set("inquiry", ([
                "侠客岛": "这里就是侠客岛了，如果想往里走，务必少不了一件雨衣，省得淋湿自己的衣服。",
                "雨衣": (: ask_yuyi :),
        ]));
         set("chat_chance_combat", 100);
         set("chat_msg_combat", ({
                 (: consider :)
         }) );
 
         set_skill("force", 300);
         set_skill("dodge", 300);
         set_skill("mysterrier", 300);
         set_skill("xianglong-zhang",300);
         set_skill("strike",300);
         set_skill("parry", 300);
         set_skill("literate", 300);
         set_skill("jiuyang-shengong", 300);
         map_skill("force", "jiuyang-shengong");
         map_skill("parry", "xianglong-zhang");
         map_skill("strike", "xianglong-zhang");
         map_skill("dodge", "mysterrier");
         prepare_skill("strike", "xianglong-zhang");
         set_temp("jiuyang-shield", 1);

         setup();
         set_temp("apply/armor_vs_force",1000);
         set_temp("apply/armor",1000);
}

string ask_yuyi()
{
     object me = this_player();
     object ob;

     if( !me->query("got_ling"))
     return "你怎么偷偷摸摸上岛来的？！就凭你还不够资格来侠客岛！\n";

 
        command("say 欢迎阁下光临侠客岛，本岛岛主自在岛中相候。");
        command("say 前面道路不太好走，但岛中人手不够，还请阁下自行前往。");
        command("say 如有招待不周之处，请勿见怪，这是一件雨衣，穿上它穿过此瀑布自然有路前行了。");
                tell_object(me, HIW"仆从在路旁一株大树后取下一件挂着的油布雨衣，随即递给了你。\n"NOR);      

                ob=new("/d/xkd/obj/yuyi");
                ob->move(me);

}
 
