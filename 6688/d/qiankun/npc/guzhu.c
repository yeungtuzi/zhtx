//guzhu.c
//by masterall
 
#include <ansi.h>
inherit "/std/char/doomnpc";
 
 
void create()
{
     set_name("孤竹",({"gu zhu","zhu"}));
     set("long",@LONG
他就是逍遥门二当家的孤竹，
逍遥门自从门主莫意闲命丧『覆雨剑』浪翻云之手后，逐渐破败，
孤竹也只好到乾坤教里躲避仇家追杀，其实在江湖上也算得上是一等一的高手。
司空晓风因此特意派他来最后坐镇乾坤教的宝藏库，不料其监守自盗，捞了不少油水。
LONG
     );
        set("title", HIC"逍遥门"NOR+HIB"二当家"NOR);
        set("nickname",  HIW "魑魅魍魉" NOR);
        set("gender","男性");
        set("attitude", "aggressive");
        set("age", 33);
        set("str", 30);
        set("con", 30);
        set("cor",37);
        set("int", 57);
        set("per", 29);
        set("con",59);
        set("cps",29);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "sword.tianmo" :)
        }) ); 
 
        set("force", 10000);
        set("max_force", 3000);
        set("force_factor", 250);
        set("max_kee", 4000);
        set("max_gin", 2000);
        set("max_sen", 2000);
        set("combat_exp", 10000000);
        set("shen",-5000000);
        set("shen_type",-1);

         set_skill("force", 300);
        set_skill("move", 200);
         set_skill("dodge", 300);
         set_skill("bat-steps", 300);
        set_skill("claw", 200);
         set_skill("parry", 200);
         set_skill("sword", 300);
         set_skill("cuixin-zhang", 200);
         set_skill("strike", 200);
         set_skill("spicyclaw", 200);
         set_skill("literate", 200);
         set_skill("mo-jian-jue", 200);
         set_skill("mo-dao-jue", 200);
         set_skill("mo-fu-jue", 200);
         set_skill("mo-chui-jue", 200);
         set_skill("mo-bian-jue", 200);
         set_skill("mo-qiang-jue", 200);
         set_skill("mo-zhang-jue", 200);
         set_skill("mo-gou-jue", 200);
         set_skill("mo-cha-jue", 200);
         set_skill("mo-ji-jue", 200);
         set_skill("tianmo-dafa", 200);
         set_skill("qiankun-danuoyi", 300);
 
         map_skill("force", "tianmo-dafa");
         map_skill("dodge", "bat-steps");
         map_skill("move", "bat-steps");
        map_skill("strike", "cuixin-zhang");
         map_skill("parry", "qiankun-danuoyi");
         map_skill("sword", "mo-jian-jue");
         map_skill("claw", "spicyclaw");

         prepare_skill("claw", "spicyclaw");
         prepare_skill("strike", "cuixin-zhang");
 
         create_family("乾坤教", 2, "护法");
         set("class", "强盗");
       
       setup();
         set_temp("apply/armor_vs_force",200);
         set_temp("apply/armor",200);
         set_temp("apply/attack",50);
         set_temp("apply/damage",200);
         set_temp("apply/defense",10);
         carry_object("/d/qiankun/obj/jian1")->wield();
         add_money("gold", random(50));
        carry_object("/d/heimuya/obj/coolsword");
        if(random(10)>8)carry_object("/d/qiankun/obj/nineflower");
        if(random(10)>8)carry_object("/d/qiankun/obj/wangyouguo");
        if(random(20)>18)carry_object("/d/xueshan/npc/obj/xarmor")->wear();
        if(random(10)>6) carry_rnd_equip(4,5);          
}
