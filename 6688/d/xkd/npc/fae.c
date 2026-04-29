// shangshan.c 赏善使者
//by masterall
 
 
#include <ansi.h>
 
inherit NPC;
 
 
void consider();
 
void create()
{
        set_name("李四", ({ "li si", "li"}) );
 
        set("title", HIG "侠客岛"+HIY"罚恶使者" NOR);
        set("gender", "男性");
        set("age", 40);
        set("long",
             "此人身形也是甚高，但十分瘦削，身穿天蓝色长衫，身阔还不及赏善使者一半，\n"
             "留一撇鼠尾须，脸色却颇为阴沉。\n"
        );
        set("attitude", "friendly");
        set("shen_type", 1);
        set("shen",3000000);
        set("str", 100);
        set("con", 100);
        set("int", 100);
        set("dex", 100);
        set("per", 30);
 
        set("force", 10000);
        set("max_force", 5000);
        set("force_factor", 250);
        set("max_kee", 5000);
        set("max_gin", 5000);
        set("max_sen", 5000);
 
        set("combat_exp", 50000000);
        set("score", 20000);
         set("chat_chance_combat", 100);
         set("chat_msg_combat", ({
                 (: consider :)
         }) );
 
         set_skill("force", 300);
         set_skill("dodge", 300);
         set_skill("mysterrier", 300);
         set_skill("xuanming-shenzhang",300);
         set_skill("strike",300);
         set_skill("parry", 300);
         set_skill("literate", 300);
         set_skill("iceforce", 300);
         map_skill("force", "iceforce");
         map_skill("parry", "xuanming-shenzhang");
         map_skill("strike", "xuanming-shenzhang");
         map_skill("dodge", "mysterrier");
         prepare_skill("strike", "xianglong-zhang");

         setup();
         set_temp("apply/armor_vs_force",1000);
         set_temp("apply/armor",1000);
}
 
