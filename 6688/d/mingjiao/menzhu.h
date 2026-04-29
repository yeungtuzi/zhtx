void init()
{
	add_action("give_quest","quest");
	::init();
}

void attempt_apprentice(object ob)
{

	string ob_fam;

        if (!(ob_fam = ob->query("guild")) || ob_fam != "明教")
	{
                command("say " + RANK_D->query_respect(ob) + "与本教素无来往，不知此话从何谈起？");
		return;
	}

        command("say 很好，很好!");
        command("recruit " + ob->query("id"));
	ob->set("title","明教教众"NOR);

	return;
}

