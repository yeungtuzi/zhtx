// attribute.c
// From ES2
// Modified by lysh

#include <dbase.h>
#include <skill.h>


int query_str()
{
        int improve = 0;

        if ( query_skill("unarmed",1) || query_skill("cuff", 1) ||query_skill("hand",1) || query_skill("strike", 1) ||query_skill("finger",1) || query_skill("claw", 1) )
        {
                if ( query_skill("cuff", 1) >= query_skill("unarmed", 1) && query_skill("cuff", 1) >= query_skill("hand", 1) && query_skill("cuff", 1) >= query_skill("strike", 1) && query_skill("cuff", 1) >= query_skill("finger", 1) && query_skill("cuff", 1) >= query_skill("claw", 1))
                        improve = (int)query_skill("cuff", 1) / 10;
                else
		if ( query_skill("unarmed", 1) >= query_skill("hand", 1) && query_skill("unarmed", 1) >= query_skill("strike", 1) && query_skill("unarmed", 1) >= query_skill("finger", 1) && query_skill("unarmed", 1) >= query_skill("claw", 1))
                        improve = (int)query_skill("unarmed", 1) / 10;
                else
		if ( query_skill("hand", 1) >= query_skill("strike", 1) && query_skill("hand", 1) >= query_skill("finger", 1) && query_skill("hand", 1) >= query_skill("claw", 1))
                        improve = (int)query_skill("hand", 1) / 10;
                else
		if ( query_skill("strike", 1) >= query_skill("finger", 1) && query_skill("strike", 1) >= query_skill("claw", 1))
                        improve = (int)query_skill("strike", 1) / 10;
                else
		if ( query_skill("finger", 1) >= query_skill("claw", 1))
                        improve = (int)query_skill("finger", 1) / 10;
                else
                        improve = (int)query_skill("claw", 1) / 10;
        }

        return (int)query("str") + (int)query("force_factor")/10 +
                query_temp("apply/strength") + improve + query("gift_imp/str");
}
int query_int()
{
        return (int)query("int") + query_temp("apply/intelligence") +
                (int)query_skill("literate", 1) / 10 + query("gift_imp/int")
                + (int)query_skill("qi", 1) / 20;
        return (int)query("int") + query_temp("apply/intelligence") +
                (int)query_skill("literate", 1) / 10 + query("gift_imp/int");
}

int query_con()
{
        return (int)query("con") + query_temp("apply/constitution") +
                (int)query_skill("force", 1) / 10 + query("gift_imp/con");
}

int query_dex()
{
        return (int)query("dex") + query_temp("apply/dexerity") +
                (int)query_skill("dodge", 1) / 10 + query("gift_imp/dex");
}
 
int query_kar()
{
	return (int)query("kar") + query("gift_imp/kar")
		+ query_temp("apply/karma")
		- (int)query("MKS") / 300;
}

int query_per()
{
        // we don't want child to suicide just because his personality...
        if( query("age") < 17 ) 
        	return (15+query_temp("apply/personality")+query("gift_imp/per")+(int)query_skill("music",1)/10);
	
	return (int)query("per")
		+ query_temp("apply/personality") + query("gift_imp/per") + (int)query_skill("music",1)/10;
}

int query_cps()
{
   int bonus;


	bonus = (int)query_skill("buddhism",1)/10-10;
	if( bonus < 0 ) bonus = 0;
   
    bonus += (int) query("cps") + (int) query("force_factor")/8 
	       + (int) query("gift_imp/cps") + query_temp("apply/composure");
   if(query("bellicosity")>0)
      bonus -= (int)query("bellicosity")/200;
   bonus += (int)query_skill("dormancy",1)/10;
   return bonus;
     
}
int query_cor()
{
	int bonus, b;

	bonus = 0;
	b = (int)query("bellicosity") / 5;
	while( (b /= 2) > 0 ) bonus ++;   
	if( bonus > 20 ) bonus = 20;
	return (int)query("cor") + bonus + query_temp("apply/courage") + query("gift_imp/cor")+(int)query_skill("yunhai-force",1)/10;
}
int query_spi()
{
        int bonus;

	bonus = (int)query_skill("taoism",1)/10-10;
	if( bonus < 0 ) bonus = 0;
	return (int)query("spi") + query("gift_imp/spi")
		+ query_temp("apply/spirituality") + bonus;
}

int query_bln()
{
	return (int)query("bln") + query("gift_imp/bln")
		+ query_temp("apply/balance");
}  

int query_wil()
{
	int bonus, b;

	bonus = 0;
	b = (int)query("bellicosity") / 10;
	while( (b /= 2) > 0 ) bonus ++;
	if( bonus > 20 ) bonus = 20;
	return (int)query("wil") + query("gift_imp/wil")
		+ query_temp("apply/will") + bonus;
}  

int query_msc()
{
	return (int)query("msc") + query("gift_imp/msc")
		+ query_temp("apply/mysticism") + (int)query_skill("spells",1)/20;
}  

int query_fav()
{
	return (int)query("fav") + query("gift_imp/fav")
		+ query_temp("apply/favor");
}  

int query_lea()
{
	return (int)query("lea") + query("gift_imp/lea")
		+ query_temp("apply/leadership") + (int)query_skill("array",1)/10;

}	

int query_elo()
{
	return (int)query("elo") + query("gift_imp/elo")
		+ query_temp("apply/eloquence") + (int)query_skill("flattering",1)/20;

}	

int query_vis()
{
	return (int)query("vis") + query("gift_imp/vis")
		+ query_temp("apply/vision") + (int)query_skill("qimen-bagua",1)/20;

}	
