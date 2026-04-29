// tiger.c
inherit NPC;

void create()
{
        set_name("天邪虎", ({ "celestial tiger","tiger" }) );
        set("race", "野兽");
        set("age", 30);
        set("long", @LONG
   这是一只天邪派的灵兽「天邪虎」，火红的毛皮上有著如白银般的
白纹，湛蓝色的眼珠中散发出妖异的光芒。
LONG
);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "roar" :),
                (: exert_function, "recover" :),
        }) );
                
        
        set("attitude", "heroism");

        set("atman", 400);
        set("max_atman", 400);
                
        set("force", 1000);
        set("max_force", 1000);
        set("force_factor", 75);
        
        set("combat_exp", 100000);
        set("limbs", ({ "头部", "身体", "尾巴","前脚", "後脚"}) );
        set("verbs", ({ "bite","claw" }) );
        
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("force", 150);
        set_skill("celestial", 150);
        set_skill("unarmed", 100);
        set_temp("apply/attack", 1);

        map_skill("force", "celestial");

//        carry_object("/d/waterfog/npc/obj/tigerskin")->wear();
                        
        setup();
}

            