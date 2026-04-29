// ouyang.c 欧阳克
//by masterall
//2003.6.30 
 
#include <ansi.h>
void consider();
 
inherit "/std/char/doomnpc";
 
 
void create()
{
        set_name("欧阳克", ({ "ouyang ke", "ke"}) );
 
        set("nickname",  HIB "毒手摧花" NOR);
        set("title", HIW "白驼山庄"+HIM"少主" NOR);
        set("gender", "男性");
        set("age", 20);
        set("long",
             "他是白驼山庄的少主欧阳克。\n"
             "自从他被杨康所害之后，被司空晓风从奄奄一息中救起。\n"
             "派他到这里来看守乾坤教宝库。\n"
             "这种声名狼藉的武林败类居然还在乾坤教有了一席之地，真让人匪夷所思。\n" 
        );
        set("attitude", "aggressive");
        set("shen_type", -1);
        set("shen",-3000000);
        set("str", 80);
        set("con", 20);
        set("int", 50);
        set("elo", 40);
        set("dex", 20);
        set("per", 30);
        set("cor", 50);
        set("cps", 50);
 
        set("force", 6000);
        set("max_force", 3000);
        set("force_factor", 250);
        set("max_kee", 4000);
        set("max_gin", 2000);
        set("max_sen", 2000);
 
        set("combat_exp", 10000000);
        set("score", 20000);
         set("chat_chance_combat", 100);
         set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
          //      (: perform_action, "staff.chan" :)
         }) );
 
         set_skill("force", 200);
         set_skill("dodge", 300);
         set_skill("lingboweibu", 300);
         set_skill("xingxiu-duzhang",300);
         set_skill("strike",200);
         set_skill("parry", 200);
         set_skill("literate", 200);
         set_skill("huntian-qigong", 200);
         set_skill("fushi-dugong", 250);
         set_skill("dugong", 250);
         set_skill("flattering", 400);
         set_skill("staff", 300);
         set_skill("dagou-bang", 300);

         map_skill("force", "huntian-qigong");
         map_skill("parry", "xingxiu-duzhang");
         map_skill("staff", "dagou-bang");
         map_skill("strike", "xingxiu-duzhang");
         map_skill("dugong", "fushi-dugong");
         map_skill("dodge", "lingboweibu");
         prepare_skill("strike", "xingxiu-duzhang");
         set("skill_mark/dagou-bang",1);

 
         setup();
         set_temp("apply/armor_vs_force",150);
         set_temp("apply/armor",150);
         set_temp("apply/attack",100);
         add_money("gold", random(40));
        if(random(10)>8) carry_object("/d/qiankun/obj/nineflower");
        carry_object("/d/qiankun/obj/shezhang")->wield();
        if(random(10)>2) carry_rnd_equip(3,3);          
}


