//ggolder.c write by lysh古怪老头 

inherit NPC;
ask_shi();
void create()
{
	set_name("怪老头", ({ "guai lao tou", "guai", "tou","lao tou" }));
	set("age", 54);
	set("gender", "男性");
	set("long", "一位爱收集古怪东西的老头。\n");
	set("attitude", "friendly");

	set("str", 24);
	set("con", 16);
	set("combat_exp", 10000);
	set("shen_type", 1);

	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("force", 40);
        set_skill("literate",100);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);

        set("chat_chance", 1);
	set("chat_msg", ({
		"林中开满了各种的野花。\n",
		}));
               set("inquiry", ([
                "十八学士" : (: ask_shi :),
        ]));

	setup();
	carry_object(__DIR__"obj/cloth")->wear();
}

int ask_shi()
{       
    object ob;    
    if (this_player()->query_temp("give-beggar"))
       {
	command("say 我不知道什么是“十八学士”，这朵野花长的也很漂亮，就送给"+ RANK_D->query_respect(this_player())+ "吧。");
	this_player()->set_temp("get-flower", 1); 
        ob=new(__DIR__"obj/yehua");
       ob->move(this_player());
        this_player()->set_temp("give-beggar",0);
        return 1;
        }
	return 0;
} 

