inherit NPC;
void create()
{
        set_name("武将" , ({ "wu jiang", "jiang" }) );
        set("long",
        "这是守卫皇宫武将，统帅锦衣卫掌管皇宫安全。\n"
        );
        set("gender", "男性");
        set("age", 20+random(10));
        set("combat_exp", 1000000);
        setup();
        add_money("silver", 10);

  //      carry_object("/d/chaoting/npc/obj/jindao")->wield();
//        carry_object("/d/chaoting/npc/obj/jinyi")->wear();

}

