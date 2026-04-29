// woman.c

inherit NPC;

void create()
{
        set_name("农妇", ({ "woman" }) );
        set("gender", "女性" );
        set("age", 23);
        set("long", "一个普普通通的农妇. \n");

        set("combat_exp", 150);
        set("attitude", "heroism");
        set_skill("unarmed", 15);
        set_skill("parry", 10);
        set_skill("force", 20); 
        set_skill("dodge", 20);
	set("chat_chance", 5);
	set("chat_msg", ({
		"西首四五位着一子",
		"婆婆，我又输了。",
	}));

	set("inquiry", ([
		"老婆婆" : "她是我婆婆",
	]));

        setup();
    	add_money("silver", 3);
        carry_object("/obj/cloth")->wear();
        
}
