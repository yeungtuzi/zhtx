  // zhou.c 周芷若
//by masterall
//2003.6.30 
 
#include <ansi.h>
 
inherit "/std/char/doomnpc";
 
 
 
void create()
{
        set_name("周芷若", ({ "zhou zhiruo", "zhou"}) );
 
        set("nickname",  HIB "毒如蛇蝎" NOR);
        set("title", BLK "峨嵋派前掌门" NOR);
        set("gender", "女性");
        set("age", 20);
        set("long",
             "她是峨嵋派前任掌门周芷若。\n"
             "自从她偷习九阴真经走火入魔后武功尽失，被司空晓风收容。\n"
             "派她到这里来看守乾坤教宝库。\n"
             "这种人尽可夫的女子已经在武林中臭名昭著，想不到乾坤教尽然是这样一个藏污纳垢之所。\n" 
        );
        set("attitude", "aggressive");
        set("shen_type", -1);
        set("shen",-500000);
        set("str", 80);
        set("con", 20);
        set("int", 50);
        set("dex", 20);
        set("per", 200);
 
        set("force", 8000);
        set("max_force", 4000);
        set("force_factor", 150);
        set("max_kee", 5000);
        set("max_gin", 1000);
        set("max_sen", 1000);
 
        set("combat_exp", 10000000);
        set("score", 20000);
         set("chat_chance_combat", 100);
         set("chat_msg_combat", ({
                (: perform_action, "dodge.ensnare" :)
         }) );
         
 
 
         set_skill("force", 200);
         set_skill("stormdance", 200);
         set_skill("dodge", 200);
         set_skill("fuliu-jian",200);
         set_skill("sword",200);
         set_skill("parry", 200);
         set_skill("literate", 200);
         set_skill("iceforce", 200);
         map_skill("force", "iceforce");
         map_skill("parry", "fuliu-jian");
         map_skill("dodge", "stormdance");
         map_skill("sword", "fuliu-jian");

 
         create_family("乾坤教", 2, "护法");
         set("class", "强盗");
 
         setup();
         set_temp("apply/armor_vs_force",50);
         set_temp("apply/armor",50);
         carry_object("/class/mingjiao/skysword")->wield();
         if(random(10)>8)carry_object("/d/qiankun/obj/nineflower");
         add_money("gold", 50);
         if(random(10)>7)carry_object("/d/qiankun/obj/shenxiancha");
         if(random(10)>4) carry_rnd_equip(3,5);          
}


