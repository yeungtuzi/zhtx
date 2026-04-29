//  /d/suzhou/npc/biaoju.h
//this is for players to learn skills in biaoju.

int recognize_apprentice(object ob)
{
	if (ob->query("biao_ju") )
		return 1;
	if (!(int)ob->query_temp("mark/biaoju"))  return 0; 
	return 1;
}

int accept_learn(object me, string skill)
{
	if (skill=="unarmed" || skill=="dodge" || skill=="parry" 
|| skill=="force" || skill=="sword" || skill=="blade" || skill=="strike" )
	{
		if (me->query("biao_ju") )
			return 1;
		if (!(int)me->query_temp("mark/biaoju"))
			return 0; 
		me->add_temp("mark/biaoju", -1);
		return 1;
	}

	return 0;
}

int accept_object(object who, object ob)
{
        if (!(int)who->query_temp("mark/biaoju"))
                who->set_temp("mark/biaoju", 0);
        if (ob->query("money_id") && ob->value() >= 1000) {
                message_vision("镖头同意指点$N一些基本武功。\n", who);
                who->add_temp("mark/biaoju", ob->value() / 50);
                return 1;
        }
        return 0;
}

