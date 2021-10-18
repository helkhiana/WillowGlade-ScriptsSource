modded class ActionDeployObject : ActionContinuousBase
{			 
	protected bool CanIPlaceHere(EntityAI kit, EntityAI item, vector pos, string GUID = ""){
		int curTime  = GetGame().GetTime();
		m_LastCheckLocation = pos;
		if (pos == vector.Zero || !item || !kit){
			m_CanPlaceHere = false;
			return m_CanPlaceHere;
		} else if (!GetBasicTerritoriesConfig().CanBuildHere(pos, item.GetType()) || !GetBasicTerritoriesConfig().CanBuildHere(pos, kit.GetType()) ){
			GetBasicTerritoriesConfig().SendNotification( GetBasicTerritoriesConfig().NoBuildZoneMessage, TerritoryIcons.NoBuildZone);
			m_CanPlaceHere = false;
			return m_CanPlaceHere;
		} else if ( GetBasicTerritoriesConfig().IsInWhiteList(item.GetType()) || GetBasicTerritoriesConfig().IsInWhiteList(kit.GetType()) ){
			m_CanPlaceHere = true;
			return m_CanPlaceHere;
		} else {
			array<Object> objects = new array<Object>;
			array<CargoBase> proxyCargos = new array<CargoBase>;
			float theRadius = GameConstants.REFRESHER_RADIUS;
			if ( kit.IsInherited(TerritoryFlagKit) ){
				theRadius = GameConstants.REFRESHER_RADIUS * 5;
			}
			GetGame().GetObjectsAtPosition(pos, theRadius, objects, proxyCargos);
			TerritoryFlag theFlag;
			if (objects){
				for (int i = 0; i < objects.Count(); i++ ){
					if ( Class.CastTo( theFlag, objects.Get(i) ) ){
						if ( kit.IsInherited(TerritoryFlagKit) ){
							GetBasicTerritoriesConfig().SendNotification(GetBasicTerritoriesConfig().TerritoryConflictMessage, TerritoryIcons.TerritoryConflict);
							#ifdef BASICMAP
							if (BASICT_Marker){
								BASICT_Marker.SetOverLaping(true);
							}
							#endif
							m_CanPlaceHere = false;
							return m_CanPlaceHere;
						}
						if (theFlag.HasRaisedFlag()){
							if (m_LastSync < curTime){
								m_LastSync = curTime + 60000;
								theFlag.SyncTerritory();
							}
							m_CanPlaceHere = theFlag.CheckPlayerPermission(GUID, TerritoryPerm.DEPLOY);
							if (!m_CanPlaceHere){
								GetBasicTerritoriesConfig().SendNotification(GetBasicTerritoriesConfig().WithinTerritoryWarning, TerritoryIcons.WithinTerritory);
							}
							return m_CanPlaceHere;
						}
					}
				}
			} 
			if (kit && kit.IsInherited(TerritoryFlagKit) ){
				#ifdef BASICMAP
				if (BASICT_Marker){
					BASICT_Marker.SetOverLaping(false);
				}
				#endif
				m_CanPlaceHere = true;
				return m_CanPlaceHere;
			}
		}
		if (GetBasicTerritoriesConfig().RequireTerritory){
			
			GetBasicTerritoriesConfig().SendNotification(GetBasicTerritoriesConfig().TerritoryRequiredWarningMessage, TerritoryIcons.TerritoryRequiredWarning);
			m_CanPlaceHere = false;
			
		} else {
			string DeSpawnWarningMessage = GetBasicTerritoriesConfig().DeSpawnWarningMessage;
			int LifeTime = 0;
			int itemLifetime = 0;
			ItemBase theItem;
			ItemBase theKit;
			string ItemName = kit.GetDisplayName();
			
			theItem = ItemBase.Cast(item);
			itemLifetime = GetBasicTerritoriesConfig().GetKitLifeTime(theItem.GetType());
			if (itemLifetime <= 0 && theItem){
				itemLifetime =  theItem.GetTSyncedLifeTime();
			}
			theKit = ItemBase.Cast(kit);
			LifeTime = GetBasicTerritoriesConfig().GetKitLifeTime(theKit.GetType());
			if (LifeTime <= 0 && theKit){
				LifeTime =  theKit.GetTSyncedLifeTime();
			}
			//Print("The Item: " + theItem.GetType() + " TSynced: " + theItem.GetTSyncedLifeTime()  + " TheKit: " + theKit.GetType() + " TSynced: " + theKit.GetTSyncedLifeTime() );
			if (itemLifetime > LifeTime){
				LifeTime = itemLifetime;
				ItemName = item.GetDisplayName();
			} 
			GetBasicTerritoriesConfig().GetKitLifeTime(kit.GetType());
			string NiceExpireTime = GetBasicTerritoriesConfig().NiceExpireTime(LifeTime);
			if (NiceExpireTime != ""){
				DeSpawnWarningMessage.Replace("$LIFETIME$", NiceExpireTime);
				DeSpawnWarningMessage.Replace("$ITEMNAME$", ItemName); 
				GetBasicTerritoriesConfig().SendNotification(DeSpawnWarningMessage, TerritoryIcons.DeSpawnWarning);
			}
			m_CanPlaceHere = true;
		}
		return m_CanPlaceHere;
	}
};