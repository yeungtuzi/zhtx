inherit NPC;
 
void create()
{
        set_name("瑷伦",  ({ "eelon"  }) );
        set("gender", "女性" );
         set("age", 37);
        set("long", @TEXT
TEXT
);
        set("attitude", "peaceful");
       set("class", "dancer");
       set("combat_exp", 3000000);
       set("score", 1000);
        set_skill("unarmed",100);
        set_skill("dodge", 100);
        set_skill("stormdance", 100);
        set_skill("tenderzhi", 100);
        map_skill("dodge","stormdance");
        map_skill("unarmed","tenderzhi");
        set("force", 4000);
        set("max_force", 3000);
        set("force_factor", 10);
        create_family("晚月庄", 1, "前辈");

        setup();
        carry_object("/d/latemoon/obj/deer_boot")->wear();
         carry_object("/d/latemoon/obj/blue_dress")->wear();
}

void attempt_apprentice(object ob)
{
     command("say 拜师! 不敢当，我都老了!你去找「芷萍」好了，看她收不收你? ");
}
