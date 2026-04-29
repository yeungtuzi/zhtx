// shangshan.c 赏善使者
//by masterall
 
 
#include <ansi.h>
 
inherit NPC;
 
void create()
{
        set_name("仆人", ({ "pu ren"}) );
 
        set("title", HIG "侠客岛"+HIY"侍从" NOR);
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
 
        set("combat_exp", 10000000);
        set("score", 20000);

 
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

