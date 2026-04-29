//teacher.c
//pock copy by yuer's laozhe.c 98.04.04


inherit NPC;
int ask_me();


void create()
{
	set_name("读千里", ({ "du qianli", "du" }));
	set("long", "读千里自诩学富五车，但为了生计只能开了一个小小的书院，\n"+
		    "收一些乡下小童，靠教书以维护生活.其实他精通草书,不过，\n"+
		    "这里没有人懂得欣赏。\n");
	set("gender", "男性");
	set("age", 50);

	set_skill("caoshu", 100);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_temp("apply/attack", 60);
	set_temp("apply/defense", 60);
	set_temp("apply/damage", 20);

	set("combat_exp", 200000);
	set("shen_type", 1);
	set("inquiry", ([
                "草书" : (: ask_me :),
                "caoshu" : (: ask_me :),

               ]) );
	setup();

}
int ask_me()
{
        if ( this_player()->query_temp("marks/ask") ) {
 	    command( "sigh");
	    return 0;
        }
        else {
	   command( "sigh");
           command( "say 可惜我最拿手的知识都派不上用场啊!");
	   command( "say 你愿意跟我学吗？只收十两银子.");
           this_player()->set_temp("marks/ask", 1);
        }
        return 1;
}

int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("mark/du"))  return 0; 
	return 1;
}

int accept_learn(object me, string skill)
{
	if (skill=="caoshu")
	{
		if (!(int)me->query_temp("mark/du"))
			return 0; 
		me->add_temp("mark/du", -1);
		return 1;
	}

	return 0;
}


int accept_object(object who, object ob)
{
	            if (!(int)who->query_temp("mark/du"))
		who->set_temp("mark/du", 0);
	   if (ob->query("money_id") && ob->value() >= 1000) {
		message_vision("读千里同意指点$N一些关于草书(caoshu)的问题。\n", who);
		who->add_temp("mark/du", ob->value() / 50);
		return 1;
                       	}

	return 0;
}

