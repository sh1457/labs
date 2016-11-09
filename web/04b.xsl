<?xml version="1.0" encoding="utf-8"?> 
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns ="http://www.w3.org/1999/xhtml"> 
<xsl:template match="eng-coll"> 
	<xsl:for-each select="vtu"> 
		<span style="font-style:italic;color:blue;">USN :
		<xsl:value-of select="usn"/><br/></span> 
		<span style="font-style:italic;color:magenta;">NAME :
		<xsl:value-of select="name"/><br/></span> 
		<span style="font-style:italic;color:indigo;">COLLEGE :
		<xsl:value-of select="college"/><br/></span> 
		<span style="font-style:italic;color:red;">BRANCH :
		<xsl:value-of select="branch"/><br/></span> 
		<span style="font-style:italic;color:green;">YEAR :
		<xsl:value-of select="year"/><br/></span> 
		<span style="font-style:italic;color:cyan;">EMAIL :
		<xsl:value-of select="email"/><br/></span> 
	</xsl:for-each> 
</xsl:template> 
</xsl:stylesheet>
