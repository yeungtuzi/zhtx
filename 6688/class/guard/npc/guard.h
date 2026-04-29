//by tlang for guarder

void init()
{
	remove_call_out("greeting");
	call_out("greeting",1,this_player());
}

void greeting()
{
	object ob=this_player();
	string callname;

	callname = RANK_D->query_rude(ob);

	if(!environment() || environment(ob)!=environment() ||
!ob->query_temp("guard_enemy") )	return;
 	command("heng "+ob->query("id"));
	command("say "+callname+"你竟然敢杀我们王符中人，你去死吧！\n");	
	kill_ob(ob);
}

int accept_kill(object killer)
{
 	int i;
	object *ob,me;
	me=this_object();
	ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me ) continue;
                if( ob[i]->query("family/family_name")!="宁王府") continue;
		if( ob[i]->query("id")==killer->query("id")) continue;
                if( userp(ob[i]) ) ob[i]->kill_ob(killer);
                else if( !ob[i]->is_killing(killer) ) ob[i]->kill_ob(killer);
		write(ob[i]->query("name")+ "吼道:"+HIY 
                "好小子, 居然敢杀我们宁王府的人,死去吧你!\n" NOR);
		killer->set_temp("guard_enemy",1);
        }
        return 1;
}

void heal()
{
        object ob=this_object();

        if (ob->query("eff_kee") < ob->query("max_kee"))
        {
                command("exert lifeheal");
                command("enforce 60");
                return;
        }
        if (ob->query("kee") < ob->query("eff_kee"))
        {
	      command("exert recover");
                return;
        }

        if (ob->query("gin") < ob->query("eff_gin"))
                command("exert regenerate");

        return;
}


