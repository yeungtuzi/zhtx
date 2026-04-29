//F_REPORT
//用来回报物品地点的。
//made by emote
string report_place_name(object ppl)
{
  if( objectp(ppl)
  &&  objectp(environment(ppl))
    )
  	
  	return environment(ppl)->query("short");
}

string report_place_basename(object ppl)
{
   if( objectp(ppl)
   &&  objectp(environment(ppl))
     )
    	return base_name(environment(ppl))+".c";
}

object report_ppl(object obj)
{
   if( objectp(obj)
  &&  objectp(environment(obj))
       )
     
     return environment(obj);
}

int reporting(object ppl,object obj)
{
    string env,env_basename;
    env = report_place_name(ppl);
    env_basename = report_place_basename(ppl);
       
   if(     objectp(ppl)
	&& objectp(obj)
	&& stringp(env)			
	&& stringp(env_basename)
     )
   {
      	CHANNEL_D->do_channel(obj,"sys", sprintf("现在 %s在%s(%s)身上在%s(%s)这个地方。" ,
                                     obj->query("name"),ppl->query("name"),getuid(ppl),
                                     env,env_basename));
        CHANNEL_D->do_channel(obj,"rumor", sprintf("现在 %s在%s(%s)身上在%s这个地方。" ,
                                     obj->query("name"),ppl->query("name"),getuid(ppl),
                                     env));
                                     
	return 1;
    }	
    return 0;
}