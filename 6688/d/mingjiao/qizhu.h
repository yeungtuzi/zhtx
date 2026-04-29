void init()
{
	add_action("give_quest","quest");
	::init();
}

void attempt_apprentice(object ob)
{
	object me  = this_object();
	mapping ob_fam;
	mapping my_fam  = me->query("family");

	string name, new_name;

        if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "明教")
	{
                command("say " + RANK_D->query_respect(ob) + "与本教素无来往，不知此话从何谈起？");
		return;
	}

	if( ob->query_skill("moni-xinfa",1) < 50 )
		return notify_fail("真可惜，你的修为不够，暂时还不能拜师。\n");

        command("say 本旗主又得一可塑之才，真是可喜可贺 !");
        command("say 恭喜你荣任明教门主！");
        command("recruit " + ob->query("id"));
	ob->set("title","明教门主"NOR);

	return;
}

