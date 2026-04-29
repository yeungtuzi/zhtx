// lin.c 林平之
//by masterall
//2003.6.30 
 
#include <ansi.h>
 
inherit "/std/char/doomnpc";
 
 
void create()
{
        set_name("林平之", ({ "lin pingzhi", "lin"}) );
 
        set("nickname",  HIW "变态阉人" NOR);
        set("title", HIG "华山派"+HIY"弃徒" NOR);
        set("gender", "无性");
        set("age", 20);
        set("long",
             "它是华山派弃徒林平之。\n"
             "它自从自宫修习辟邪剑法以来，性格变得极为怪异，喜怒无常，杀人无算。\n"
             "司空晓风在它重伤之时收容它为己所用，表面上对它恭恭敬敬，\n"
             "实际上在司空晓风眼中，林平之已与废人无异。\n" 
        );
        set("attitude", "aggressive");
        set("shen_type", -1);
        set("shen",-500000);
        set("str", 80);
        set("con", 20);
        set("int", 50);
        set("dex", 20);
        set("per", 30);
        set("cor", 80);
        set("cps", 80);
        set("chat_chance_combat", 100); 
        set("chat_msg_combat", ({
                (: perform_action, "sword.cimu" :),
                (: exert_function, "kuihua" :),
        }) );
 
        set("force", 4000);
        set("max_force", 2000);
        set("force_factor", 150);
        set("max_kee", 5000);
        set("max_gin", 1500);
        set("max_sen", 1500);
 
        set("combat_exp", 10000000);
        set("score", 20000);

         set_skill("force", 200);
         set_skill("dodge", 200);
         set_skill("kuihua-shengong", 200);
         set_skill("pixie-sword",200);
         set_skill("sword",200);
         set_skill("parry", 200);
         set_skill("literate", 200);
         map_skill("force", "kuihua-shengong");
         map_skill("dodge", "kuihua-shengong");
         map_skill("parry", "pixie-sword");
         map_skill("sword", "pixie-sword");

 
         create_family("日月神教", 2, "护法");
         set("class", "强盗");
 
         setup();
         set_temp("apply/armor_vs_force",50);
         set_temp("apply/armor",50);
         set_temp("apply/damage",100);
         set_temp("apply/attack",50);
         carry_object("/d/heimuya/obj/coolsword")->wield();
         add_money("gold", random(30));

        if(random(10)>8)carry_object("/d/qiankun/obj/nineflower");
        if(random(10)>8) carry_object("/d/huashan/obj/jiasha");

        if(random(10)>4) carry_rnd_equip(3,3);          
}
 



