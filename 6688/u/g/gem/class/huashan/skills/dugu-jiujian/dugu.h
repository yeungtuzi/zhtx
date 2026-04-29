//dugu.h
//by Emote 5/20/2000
//for check if victim have a certain weapon
int check_weapon(object target,string weapon_name)
{
    object weapon;
	if(!objectp(target) && living(target)) return 0;
    if (weapon_name=="strike")
    {
    	if(objectp(weapon=target->query_temp("weapon")))
    	return 0;
    	return 1;
    }  
    else
    { 
    	if (!objectp(weapon = target->query_temp("weapon"))
        || (string)weapon->query("skill_type") != weapon_name)
    		return 0;
    	return 1;
    }	
}

int check_user(object me,object target)
{
	int per_lev,per_power,victim_exp;
      if(!objectp(target) 
       || target->is_ghost() 
       || target->query("eff_kee") < 1
       || (environment(me)!=environment(target))
       || me->is_ghost())             
      {
          message_vision(GRN"$N剑式一停，背剑凝立，停手不攻。\n"NOR,me);
		  return 0;
      }
	  if( !me->visible(target) )
         {
             per_lev = (int)me->query_skill("perception",1);
             per_power = per_lev*per_lev*per_lev;
             victim_exp = (int)target->query("combat_exp");
             per_power = random(per_power);
             if(per_power<victim_exp/4)
              {
                if( per_power>victim_exp/8 )
                  message_vision(GRN"\n$N只觉脑中一片茫然，根本无法探听出$n的一点消息。\n"NOR,me,target);
                me->set_temp("guarding", 1);                            
				return 0;
			 }                               
             message_vision(GRN"\n$N身形凝立不动，侧耳倾听。\n"NOR,me);
          }                       
	  return 1;
}