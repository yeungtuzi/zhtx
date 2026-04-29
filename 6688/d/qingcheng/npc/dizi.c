// trainee.c

inherit NPC;

void create()
{
	set_name("镖局弟子", ({ "dizi" }) );
	set("gender", "男性" );
	set("age", 19);
	set("long", "你看到一位身材高大的汉子，正在辛苦地操练著。\n");
	set("combat_exp", 1000);
	setup();
	carry_object("obj/cloth")->wear();
	
}
