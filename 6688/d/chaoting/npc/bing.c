inherit NPC;
void create()
{
        set_name("锦衣卫" , ({ "jinyi wei", "wei" }) );
        set("long",
        "这是守卫皇宫的锦衣卫，身穿锦衣，手拿金刀，威风凛凛。\n"
        );
        set("gender", "男性");
        set("age", 20+random(10));
        set("combat_exp", 500000);
        setup();
        add_money("silver", 10);

        carry_object("/d/chaoting/npc/obj/jindao")->wield();
        carry_object("/d/chaoting/npc/obj/jinyi")->wear();

}

