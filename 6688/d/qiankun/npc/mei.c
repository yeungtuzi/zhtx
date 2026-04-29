// chen.c 梅超风
//by masterall
//2003.6.30 
 
#include <ansi.h>
 
inherit "/std/char/doomnpc";
 
 
void consider();
 
void create()
{
        set_name("梅超风", ({ "mei chaofeng", "mei"}) );
 
        set("nickname",  RED "铁尸" NOR);
        set("title", GRN "桃花岛逆徒" NOR);
        set("gender", "女性");
        set("age", 40);
        set("long",
             "她是黄药师的三弟子，是桃花岛四大弟子\n"
            "“陈、梅、曲、陆”中的梅超风\n"
             "自从他和陈玄风窃得九阴真经私奔以后，就隐迹江湖\n"
             "想不到她居然躲在这里。\n" 
        );
        set("attitude", "aggressive");
        set("shen_type", -1);
        set("shen",-500000);
        set("str", 80);
        set("con", 20);
        set("int", 50);
        set("dex", 20);
        set("per", 10);
        set("cor", 30);
        set("cps", 30);
        set("bln", 30);
 
        set("force", 8000);
        set("max_force", 4000);
        set("force_factor", 250);
        set("max_kee",5000);
        set("max_gin", 1000);
        set("max_sen", 1000);
 
        set("combat_exp", 10000000);
        set("score", 20000);
         set("chat_chance_combat", 100);
         set("chat_msg_combat", ({
                 (: consider :)
         }) );
         

         set_skill("force", 200);
         set_skill("dodge", 200);
         set_skill("claw",200);
         set_skill("parry", 200);
         set_skill("literate", 200);
         set_skill("taohua-force", 200);
         set_skill("fall-steps", 200);
         set_skill("spicyclaw",200);
         set_skill("cuixin-zhang",200);
         set_skill("strike",200);
 
         map_skill("force", "taohua-force");
         map_skill("dodge", "fall-steps");
         map_skill("strike", "cuixin-zhang");
         map_skill("claw","spicyclaw"); 
         map_skill("parry", "spicyclaw");
         prepare_skill("claw","spicyclaw");
         prepare_skill("strike","cuixin-zhang");

 
 
         create_family("乾坤教", 2, "护法");
         set("class", "强盗");
 
         setup();
         set_temp("apply/armor_vs_force",50);
         set_temp("apply/armor",50);
         set_temp("apply/damage",50);
         set_temp("apply/attack",50);
         add_money("gold", random(50));
        if(random(10)>8)carry_object("/d/qiankun/obj/nineflower");
        if(random(10)>4) carry_rnd_equip(3,5);          
}
 
 
void consider()
{
         object *enemy,target;
         enemy = query_enemy() - ({ 0 });
         target = enemy[random(sizeof(enemy))]; 
         
         command("exert tanzhi " + target->query("id"));
}

