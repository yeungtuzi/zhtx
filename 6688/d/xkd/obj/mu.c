 // shangshan.c 赏善使者
//by masterall
 
 
#include <ansi.h>
 
inherit NPC;
 
 
void consider();
 
void create()
{
       set_name("木剑封", ({ "mu jianfeng", "mu"}) );
 
        set("title", HIG "侠客岛"+HIY"岛主" NOR);
        set("nickname", HIR "与世无争" NOR);
        set("gender", "男性");
        set("age", 60);
        set("long",
             "他就是传说中侠客岛的二位岛主之一。\n"
             "连名扬天下的赏善罚恶二使在他的面前都规规矩矩的，真不知他的功夫到了怎样的一个境界。\n"
        );
        set("attitude", "friendly");
        set("shen_type", 1);
        set("shen",3000000);
        set("str", 100);
        set("con", 100);
        set("int", 100);
        set("dex", 100);
        set("per", 30);
 
        set("force", 20000);
        set("max_force", 10000);
        set("force_factor", 250);
        set("max_kee", 5000);
        set("max_gin", 5000);
        set("max_sen", 5000);
 
        set("combat_exp", 100000000);
        set("score", 20000);
         set("chat_chance_combat", 100);
         set("chat_msg_combat", ({
                 (: consider :)
         }) );
 
         set_skill("force", 400);
         set_skill("dodge", 400);
         set_skill("mysterrier", 400);
         set_skill("xuanming-shenzhang",400);
         set_skill("strike",400);
         set_skill("parry", 400);
         set_skill("literate", 400);
         set_skill("iceforce", 400);
         map_skill("force", "iceforce");
         map_skill("parry", "xuanming-shenzhang");
         map_skill("strike", "xuanming-shenzhang");
         map_skill("dodge", "mysterrier");
         prepare_skill("strike", "xianglong-zhang");

         setup();
         set_temp("apply/armor_vs_force",1000);
         set_temp("apply/armor",1000);
         carry_object("/d/xkd/obj/mucloth")->wear();
}
 
