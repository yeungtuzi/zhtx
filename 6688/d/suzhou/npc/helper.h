//helper.h
//modified by tlang for teaching players skills

int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("marks/helper"))  return 0; 
	return 1;
}

int accept_learn(object me, string skill)
{
	if (!(int)me->query_temp("marks/helper"))
			return 0; 
	me->add_temp("marks/helper", -1);
		return 1;
}

int accept_object(object who, object ob)
{
	object me=this_object();

        if (!(int)who->query_temp("marks/helper"))
                who->set_temp("marks/helper", 0);
        if (ob->query("money_id") && ob->value() >= 1000) {
                message_vision("$N同意指点$N一些基本武功。\n", me,who);
                who->add_temp("marks/helper", ob->value() / 50);
                return 1;
        }
        return 0;
}

