void init()
{
	object bandit,me=this_player();
	if ( userp(me) ) 
	{

		if(present("long dan",me) ||present("jinxian lian",me)||present("tiepi shihu",me)||present("yiyuan xianlu",me)||present("lingshan yuye",me)||present("shennong zhi cao",me) )
		{
			if ( ( random(100) > 90 ) && ( me->query("bellicosity") > 2000 ) )
			{
				bandit=new("/u/z/zephyr/sunflower/npc/bandit");
				bandit->move(this_object());
				write(HIR"忽然从旁边树丛里窜出一个黑影，黑影大喝一声：\n"+
				"往哪儿跑？给我站住！\n"NOR,me);
				bandit->kill_ob(me);
				me->fight_ob(bandit); 
			}
		}
	}
}
